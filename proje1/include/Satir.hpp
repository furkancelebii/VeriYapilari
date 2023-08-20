#ifndef SATIR_HPP
#define SATIR_HPP
#include "SatirDugum.hpp"
#include <iomanip>

class Satir {
private:
    SatirDugum *head;
    int size;
    SatirDugum* SiraninOncesiniBul(int index);
public:
    Satir();
    int Count()const;
    bool isEmpty()const;
    void ekle(const int& item);
    void arayaEkle(int index, const int& item);
    const int& first();
    const int& last();
    int indexOf(const int& item);
    void sil(const int& item);
    void removeAt(int index);
    bool bul(const int& item);
    void tersCevir();
    const int& elementAt(int index);
    void temizle();
    friend ostream& operator<<(ostream& screen, Satir& rgt);
    void dugumPozisyonunaGoreTersSiraYazdir(int index);
    void tersSiraYazdir();
    void satirYazdir(int x, int y);
    ~Satir();
};

#endif