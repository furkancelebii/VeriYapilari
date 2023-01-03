#ifndef YONETICIDUGUM_HPP
#define YONETICIDUGUM_HPP
#include "Satir.hpp"
class YoneticiDugum {
public:
    Satir* data;
    double ortalama;
    YoneticiDugum *next;
    YoneticiDugum *prev;

    YoneticiDugum(Satir* data, YoneticiDugum *next, YoneticiDugum *prev);
    YoneticiDugum(Satir* data, YoneticiDugum *next);
    YoneticiDugum(Satir* data);
    double ortalamaHesapla();
};
#endif
