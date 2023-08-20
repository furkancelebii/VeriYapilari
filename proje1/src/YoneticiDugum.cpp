#include "YoneticiDugum.hpp"
YoneticiDugum::YoneticiDugum(Satir* data, YoneticiDugum *next , YoneticiDugum *prev) {
    this->data = data;
    this->next = next;
    this->prev = prev;
    this->ortalama = ortalamaHesapla();
}
YoneticiDugum::YoneticiDugum(Satir* data, YoneticiDugum *next ) {
    this->data = data;
    this->next = next;
    this->prev = prev;
    this->ortalama = ortalamaHesapla();
}
YoneticiDugum::YoneticiDugum(Satir* data) {
    this->data = data;
    this->next = next;
    this->prev = prev;
    this->ortalama = ortalamaHesapla();
}
double YoneticiDugum::ortalamaHesapla() {
    double total = 0;
    if (this->data->isEmpty())
        return total;

    int count = this->data->Count();
    for (int i = 0; i < count; ++i) {
        total += this->data->elementAt(i);
    }
    return total / count;
}