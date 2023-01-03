#ifndef SATIRDUGUM_HPP
#define SATIRDUGUM_HPP
#include <iostream>
using namespace std;

class SatirDugum {
public:
    int data;
    SatirDugum *next;
    SatirDugum *prev;
    SatirDugum(const int data, SatirDugum *next, SatirDugum *prev);
    SatirDugum(const int data, SatirDugum *next);
    SatirDugum(const int data);
};
#endif