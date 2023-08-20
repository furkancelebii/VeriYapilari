#ifndef DUGUMAGAC_HPP
#define DUGUMAGAC_HPP

class DugumAgac {
public:
    int veri;        // Düğümün taşıdığı veri değeri
    DugumAgac* sol;  // Sol alt düğümün işaretçisi
    DugumAgac* sag; // Sağ alt düğümün işaretçisi
    DugumAgac(int deger); // Kurucu fonksiyon, bir düğüm oluşturur ve veri değerini ayarlar
};

#endif

