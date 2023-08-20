#include "SatirDugum.hpp"
SatirDugum::SatirDugum(const int data, SatirDugum *next , SatirDugum *prev ) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}
SatirDugum::SatirDugum(const int data, SatirDugum *next) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}
SatirDugum::SatirDugum(const int data) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}