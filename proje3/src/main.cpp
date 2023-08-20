#include <iostream>
#include "AsagiListe.hpp"
#include "YukariListe.hpp"
#include "FileReader.hpp"
using namespace std;

int main()
{
	//Dosya okumayý açýyorum
    FileReader fileReader("Sayilar.txt");
    if (!fileReader.isOpened()) {
        std::cout << "Dosya Acilamadi..." << std::endl;
        return 1;
    }

    int listSayac = 0; // listelerin sayýsýný tutmasý için deðiþken tanýmlýyoruz.
    YukariListe* dinamikYukariListeler = nullptr; // dinamikYukariListeler'ýn dinamik dizisi.
    AsagiListe* dinamikAsagiListeler = nullptr;   // DinamikAsagiListeler'ýn dinamik dizisi.

    string line;
    while (fileReader.getNextLine(line))
    {
        YukariListe yukariListe;
        AsagiListe asagiListe;

        istringstream isstream(line);
        int sayi;
        while (isstream >> sayi)
        {
            yukariListe.ekle(sayi / 10);
            asagiListe.ekle(sayi % 10);
        }

       // dinamik dizilerin boyutunu bir arttýrýyoruz ve yeni listeler ekliyoruz.
        YukariListe* geciciYukariListeler = new YukariListe[listSayac + 1];
        AsagiListe* geciciAsagiListeler = new AsagiListe[listSayac + 1];
        for (int i = 0; i < listSayac; i++)
        {
            geciciYukariListeler[i] = dinamikYukariListeler[i];
            geciciAsagiListeler[i] = dinamikAsagiListeler[i];
        }
        geciciYukariListeler[listSayac] = yukariListe;
        geciciAsagiListeler[listSayac] = asagiListe;
		
		//Bellek temizleme iþlemlerini yapýyoruz.

        delete[] dinamikYukariListeler;
        delete[] dinamikAsagiListeler;

        dinamikYukariListeler = geciciYukariListeler;
        dinamikAsagiListeler = geciciAsagiListeler;

        listSayac++;
    }

    int konumA, konumB;
    cout << "Konum A= ";
    cin >> konumA;
    cout << "Konum B= ";
    cin >> konumB;

    if (konumA >= 0 && konumA < listSayac && konumB >= 0 && konumB < listSayac)
    {
        dinamikYukariListeler[konumA].veriDegis(dinamikAsagiListeler[konumB]);
    }
    else
    {
        cout << "Geçersiz Konum !!!!" << endl;
        return 1;
    }

    for (int i = 0; i < listSayac; i++)
    {
        dinamikYukariListeler[i].tersCevir();
    }

    for (int i = 0; i < listSayac; i++)
    {
        Node* newHead = tersListeNode(dinamikAsagiListeler[i].getHead());
        dinamikAsagiListeler[i].setHead(newHead);
    }

    double* toplamYukari = nullptr;    // toplam yukarý yönlü ortalamalarýn dinamik dizisini yapýyoruz.
    double* toplamAsagi = nullptr; // toplam aþaðý yönlü ortalamalarýn dinamik dizisini yapýyoruz.

    size_t maxSizeYukari = 0;
    for (int i = 0; i < listSayac; i++)
    {
        size_t size = 0;
        Node* konum = dinamikYukariListeler[i].getHead();
        while (konum)
        {
            konum = konum->ileri;
            ++size;
        }
        maxSizeYukari = max(maxSizeYukari, size);
    }

    size_t maxSizeAsagi = 0;
    for (int i = 0; i < listSayac; i++)
    {
        size_t size = 0;
        Node* konum = dinamikAsagiListeler[i].getHead();
        while (konum)
        {
            konum = konum->ileri;
            ++size;
        }
        maxSizeAsagi = max(maxSizeAsagi, size);
    }

    toplamYukari = new double[maxSizeYukari];     
    toplamAsagi = new double[maxSizeAsagi]; 

    fill_n(toplamYukari, maxSizeYukari, 0.0);
    fill_n(toplamAsagi, maxSizeAsagi, 0.0);

    size_t* yukariSatir = new size_t[maxSizeYukari];     // yukarý doðru olan listenin satýr sayýmlarýný yapýyoruz.
    size_t* asagiSatir = new size_t[maxSizeAsagi]; 		// aþaðý doðru olan listenin satýr sayýmlarýný yapýyoruz.


    fill_n(yukariSatir, maxSizeYukari, 0);
    fill_n(asagiSatir, maxSizeAsagi, 0);

    for (size_t satir = 0; satir < listSayac; ++satir)
    {
        Node* konumYukari = dinamikYukariListeler[satir].getHead();
        Node* konumAsagi = dinamikAsagiListeler[satir].getHead();
        size_t sutun = 0;

        while (konumYukari && konumAsagi)
        {
            toplamYukari[sutun] += static_cast<double>(konumYukari->veri);
            toplamAsagi[sutun] += static_cast<double>(konumAsagi->veri);

            yukariSatir[sutun] += 1;
            asagiSatir[sutun] += 1;

            konumYukari = konumYukari->ileri;
            konumAsagi = konumAsagi->ileri;
            ++sutun;
        }
    }
// yukarý ve aþaðý yönlü listelerin ortalamasýný tutmasý için deðiþkenler tanýmlayýp sýfýra eþitliyoruz. ?

    double totalYukari = 0.0;
    double totalAsagi = 0.0;


    for (size_t sutun = 0; sutun < maxSizeYukari; ++sutun)
    {
        if (yukariSatir[sutun] != 0)
        {
            double ort = toplamYukari[sutun] / yukariSatir[sutun];
            totalYukari += ort;

        }
    }

    for (size_t sutun = 0; sutun < maxSizeAsagi; ++sutun)
    {
        if (asagiSatir[sutun] != 0)
        {
            double ort = toplamAsagi[sutun] / asagiSatir[sutun];
            totalAsagi += ort;

        }
    }
	//Bellek temizleme iþlemlerini yapýyoruz.

    delete[] dinamikYukariListeler;
    delete[] dinamikAsagiListeler;
    delete[] toplamYukari;
    delete[] toplamAsagi;
    delete[] yukariSatir;
    delete[] asagiSatir;

    cout << endl;
	//istenen ortalama deðerlerini ekrana yazdýrýyoruz.

    cout << "Toplam Yukarý Ortalama: " << totalYukari << endl;
    cout << "Toplam Aþaðý Ortalama: " << totalAsagi << endl;

    return 0;
}
