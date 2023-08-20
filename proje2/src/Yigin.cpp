/**
* @file AsagiListe
* @description Sayilar.txt dosyasını okuyan ve içerisindeki sayıları ağaçlarla ASCII tablosuna göre yazdıran program
* @course 1. Öğretim A grubu.
* @assignment 2. Ödev.
* @date 09.08.2023.
* @author Umut Danış G191210097 umut.danis@ogr.sakarya.edu.tr -Mazhar Furkan Çelebi G191210033 mazhar.celebi@ogr.sakarya.edu.tr
*/
#include "Yigin.hpp"
#include <iostream>

Yigin::Yigin() : tepe(-1) {}  // Yığın başlatılır, üst indis -1 olarak ayarlanır

void Yigin::push(int deger) {
    if (tepe < MAX - 1) {
        tepe++;
        elemanlar[tepe] = deger;  // Eleman yığına eklenir
    } else {
        std::cerr << "Yigin is full." << std::endl;  // Yığın doluysa hata mesajı verilir
    }
}

int Yigin::pop() {
    if (!isEmpty()) {
        int veri = elemanlar[tepe];  // Üstteki eleman çıkarılır
        tepe--;
        return veri;
    } else {
        std::cerr << "Yigin is empty." << std::endl;  // Yığın boşsa hata mesajı verilir
        return -1;
    }
}

int Yigin::top() {
    if (!isEmpty()) {
        return elemanlar[tepe];  // Üstteki eleman döndürülür
    } else {
        std::cerr << "Yigin is empty." << std::endl;  // Yığın boşsa hata mesajı verilir
        return -1;
    }
}

bool Yigin::isEmpty() {
    return tepe == -1;  // Üst indis -1 ise yığın boştur
}
