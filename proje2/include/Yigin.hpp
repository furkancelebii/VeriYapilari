#ifndef YIGIN_HPP
#define YIGIN_HPP

class Yigin {
private:
    static const int MAX = 1000;  // Yığının maksimum boyutu
    int elemanlar[MAX];  // Yığını depolamak için bir dizi
    int tepe;  // Yığının üstündeki elemanın dizideki indeksi

public:
    // Kurucu fonksiyon, yığını başlatır ve üst indisini -1 olarak ayarlar
    Yigin();

    // Yığına yeni bir eleman ekler
    void push(int deger);

    // Yığının üstündeki elemanı çıkarır ve döndürür
    int pop();

    // Yığının üstündeki elemanı döndürür
    int top();

    // Yığının boş olup olmadığını kontrol eder
    bool isEmpty();
};

#endif
