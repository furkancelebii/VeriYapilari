#ifndef OKUEKLE_HPP
#define OKUEKLE_HPP
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Satir.hpp"
#include "Yonetici.hpp"

class OkuEkle {
private:
    std::string fileName;
    int satirSayaci();
    Satir **lines;
    void readLine();
public:
    OkuEkle(std::string);
    ~OkuEkle();
    Yonetici* YoneticiDoldur();
};

#endif 