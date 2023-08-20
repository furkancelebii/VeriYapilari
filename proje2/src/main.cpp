/**
* @file AsagiListe
* @description Sayilar.txt dosyasını okuyan ve içerisindeki sayıları ağaçlarla ASCII tablosuna göre yazdıran program
* @course 1. Öğretim A grubu.
* @assignment 2. Ödev.
* @date 09.08.2023.
* @author Umut Danış G191210097 umut.danis@ogr.sakarya.edu.tr -Mazhar Furkan Çelebi G191210033 mazhar.celebi@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>  // Windows için Sleep işlevini kullanmak için
#include "Yigin.hpp"  // Kendi oluşturduğunuz Stack sınıfı başlık dosyası
#include "BinaryBulma.hpp"  // Kendi oluşturduğunuz BinaryBulma sınıfı başlık dosyası

int main() {
    std::ifstream inputFile("Sayilar.txt");  // Sayıları içeren metin dosyasını açar
    if (!inputFile) {
        std::cerr << "Dosya acilamadi." << std::endl;
        return 1;
    }

    Yigin yigin;  // Yığıt veri yapısı oluşturulur
    BinaryBulma ebuyukAgac;  // En büyük yükseklik ve toplama sahip ikili arama ağacı oluşturulur

    std::string bulunanSatir;
    while (std::getline(inputFile, bulunanSatir)) {
        std::string output;  // Her satır için postorder sonuçlarını biriktirecek string

        std::istringstream lineStream(bulunanSatir);
        int num;
        while (lineStream >> num) {
            // Çift sayıyı bulur ve yığıttaki sayıları kullanarak yeni bir ağaç oluşturur
            if (num % 2 == 0 && !yigin.isEmpty() && num > yigin.top()) {
                BinaryBulma yeniAgac;
                while (!yigin.isEmpty()) {
                    yeniAgac.ekle(yigin.pop());
                }
                // Oluşturulan ağacın yüksekliği ve toplamı, en büyük ağacınkini geçerse günceller
                if (yeniAgac.getYukseklik() > ebuyukAgac.getYukseklik() ||
                    (yeniAgac.getYukseklik() == ebuyukAgac.getYukseklik() && yeniAgac.getToplam() > ebuyukAgac.getToplam())) {
                    ebuyukAgac = yeniAgac;
                }
            }
            yigin.push(num);  // Sayıyı yığıta ekler
        }

        // Yığıttaki sayıları kullanarak yeni bir ağaç oluşturur
        BinaryBulma yeniAgac;
        while (!yigin.isEmpty()) {
            yeniAgac.ekle(yigin.pop());
        }
        // Oluşturulan ağacın yüksekliği ve toplamı, en büyük ağacınkini geçerse günceller
        if (yeniAgac.getYukseklik() > ebuyukAgac.getYukseklik() ||
            (yeniAgac.getYukseklik() == ebuyukAgac.getYukseklik() && yeniAgac.getToplam() > ebuyukAgac.getToplam())) {
            ebuyukAgac = yeniAgac;
        }

        // En büyük yükseklik ve toplama sahip ağacı postorder olarak gezerek sonuçları biriktirir
        ebuyukAgac.geziciPost(ebuyukAgac.kok, output);

        ebuyukAgac.temizle();  // En büyük ağacı temizler

        // Sonuçları ekrana yazdırır ve kısa bir gecikme ekler
        for (char c : output) {
            std::cout << c << " ";
        }
        Sleep(10);  // Ekranda sonuçları basarken 10 milisaniye bekliyorum.
        std::cout << std::endl;  // Her satır sonunda bir satır atlar
    }

    inputFile.close();  // Dosyayı kapatır

    return 0;
}