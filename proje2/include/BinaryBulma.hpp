#ifndef BINARYBULMA_HPP
#define BINARYBULMA_HPP

#include <string>

class BinaryBulma {
private:
    struct DugumAgac {
        int veri;
        DugumAgac* sol;
        DugumAgac* sag;
        DugumAgac(int deger);
    };

public:
    DugumAgac* kok;  // İkili arama ağacının kök düğümü

    // Kurucu fonksiyon, ağaç oluşturulduğunda kök düğümü nullptr olarak ayarlanır
    BinaryBulma();

    // Ağaca yeni bir düğüm ekler
    void ekle(int deger);

    // Ağacın yüksekliğini hesaplar ve döndürür
    int getYukseklik();

    // Ağacın tüm düğümlerindeki sayıları toplar ve döndürür
    int getToplam();

    // Ağacı temizler, yani tüm düğümleri siler ve belleği serbest bırakır
    void temizle();

    // Postorder gezisi yaparak düğüm değerlerini biriktirir
    void geziciPost(DugumAgac* dugumKonum, std::string& output);

private:
    // Yeni bir düğüm eklemek için özel yardımcı fonksiyon (rekürsif)
    DugumAgac* ekle(DugumAgac* dugumKonum, int deger);

    // Düğümden başlayarak ağacın yüksekliğini hesaplar (rekürsif)
    int yukseklik(DugumAgac* dugumKonum);

    // Düğümden başlayarak ağacın tüm düğümlerindeki sayıları toplar (rekürsif)
    int toplam(DugumAgac* dugumKonum);

    // Düğümden başlayarak ağacı temizler (rekürsif)
    void temizle(DugumAgac* dugumKonum);
};

#endif
