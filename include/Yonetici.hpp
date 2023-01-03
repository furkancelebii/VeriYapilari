#ifndef YONETICI_HPP
#define YONETICI_HPP
#include <iostream>
#include "Satir.hpp"
#include "YoneticiDugum.hpp"
#include <stdlib.h>     
#include <time.h>    
#include "ConsolePosition.hpp"

class Yonetici {
private:
    YoneticiDugum *head;
    int size;
    YoneticiDugum* SiraninOncesiniBul(int index);
    YoneticiDugum* SiraBul(int index);
public:
    Yonetici();
    int Count()const;
    bool isEmpty()const;
    void ekle(Satir*& item);
    void arayaEkle(int index, Satir*& item);
    Satir*& first();
    Satir*& last();
    int indexOf(Satir*& item);
    void sil(Satir*& item);
    void randomSatirSilme(int index, int inlineIndex);
    void ortalamaHesapla(int index);
    int randomUretici(int index);
    void removeAt(int index);
    void dugumTasi(int from, int to);
    bool bul(Satir*& item);
    void tersCevir();
    void ortalamaSirala();
    Satir*& elementAt(int index);
    void temizle();
    void printIndex(int index, int x, int y);
    ~Yonetici();
};
#endif