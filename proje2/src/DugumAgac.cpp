/**
* @file AsagiListe
* @description Sayilar.txt dosyasını okuyan ve içerisindeki sayıları ağaçlarla ASCII tablosuna göre yazdıran program
* @course 1. Öğretim A grubu.
* @assignment 2. Ödev.
* @date 09.08.2023.
* @author Umut Danış G191210097 umut.danis@ogr.sakarya.edu.tr -Mazhar Furkan Çelebi G191210033 mazhar.celebi@ogr.sakarya.edu.tr
*/
#include "DugumAgac.hpp"

DugumAgac::DugumAgac(int deger) : veri(deger), sol(nullptr), sag(nullptr) {}
// DugumAgac sınıfının kurucu fonksiyonu. Yeni bir düğüm oluşturur ve veri değerini, sol ve sağ işaretçileri ayarlar.
