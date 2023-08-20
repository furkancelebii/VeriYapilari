/**
* @file AsagiListe
* @description Sayilar.txt dosyasını okuyan ve içerisindeki sayıları ağaçlarla ASCII tablosuna göre yazdıran program
* @course 1. Öğretim A grubu.
* @assignment 2. Ödev.
* @date 09.08.2023.
* @author Umut Danış G191210097 umut.danis@ogr.sakarya.edu.tr -Mazhar Furkan Çelebi G191210033 mazhar.celebi@ogr.sakarya.edu.tr
*/
#include "BinaryBulma.hpp"

// DugumAgac sınıfının kurucu fonksiyonu
BinaryBulma::DugumAgac::DugumAgac(int deger) : veri(deger), sol(nullptr), sag(nullptr) {}

// BinaryBulma sınıfının kurucu fonksiyonu
BinaryBulma::BinaryBulma() : kok(nullptr) {}

// İkili arama ağacına yeni bir düğüm ekler
void BinaryBulma::ekle(int deger) {
    kok = ekle(kok, deger);
}

// Ağacın yüksekliğini hesaplar ve döndürür
int BinaryBulma::getYukseklik() {
    return yukseklik(kok);
}

// Ağacın tüm düğümlerindeki sayıları toplar ve döndürür
int BinaryBulma::getToplam() {
    return toplam(kok);
}

// Ağacı temizler, yani tüm düğümleri siler ve belleği serbest bırakır
void BinaryBulma::temizle() {
    temizle(kok);
    kok = nullptr;
}

// Postorder gezisi yaparak düğüm değerlerini biriktirir
void BinaryBulma::geziciPost(DugumAgac* dugumKonum, std::string& output) {
    if (dugumKonum == nullptr) {
        return;
    }
    geziciPost(dugumKonum->sol, output);
    geziciPost(dugumKonum->sag, output);
    output += static_cast<char>(dugumKonum->veri);
}

//Yeni bir düğüm ekler (rekürsif)
BinaryBulma::DugumAgac* BinaryBulma::ekle(DugumAgac* dugumKonum, int deger) {
    if (dugumKonum == nullptr) {
        return new DugumAgac(deger);
    }
    if (deger < dugumKonum->veri) {
        dugumKonum->sol = ekle(dugumKonum->sol, deger);
    } else if (deger > dugumKonum->veri) {
        dugumKonum->sag = ekle(dugumKonum->sag, deger);
    }
    return dugumKonum;
}

//Düğümden başlayarak ağacın yüksekliğini hesaplar (rekürsif)
int BinaryBulma::yukseklik(DugumAgac* dugumKonum) {
    if (dugumKonum == nullptr) {
        return 0;
    }
    int solYukseklik = yukseklik(dugumKonum->sol);
    int sagYukseklik = yukseklik(dugumKonum->sag);
    return 1 + std::max(solYukseklik, sagYukseklik);
}

//Düğümden başlayarak ağacın tüm düğümlerindeki sayıları toplar (rekürsif)
int BinaryBulma::toplam(DugumAgac* dugumKonum) {
    if (dugumKonum == nullptr) {
        return 0;
    }
    return dugumKonum->veri + toplam(dugumKonum->sol) + toplam(dugumKonum->sag);
}

//Düğümden başlayarak ağacı temizler (rekürsif)
void BinaryBulma::temizle(DugumAgac* dugumKonum) {
    if (dugumKonum == nullptr) {
        return;
    }
    temizle(dugumKonum->sol);
    temizle(dugumKonum->sag);
    delete dugumKonum;
}