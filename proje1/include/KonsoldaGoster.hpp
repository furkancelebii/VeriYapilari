#ifndef KONSOLDAGOSTER_HPP
#define KONSOLDAGOSTER_HPP
#include "Yonetici.hpp"
#include "ConsolePosition.hpp"
#define DisplayperOnePage 8
#define BeginOffset 0
enum Direction {
    up = 0,
    down = 1,
    refresh = 2,
};
enum PageDirection {
    upPage = 0,
    downPage = 1,
};
class KonsoldaGoster {
private:
    Yonetici *yonetici;
    int state;
    int beginOffset;
    int finishOffset;
    void setOffsets();
public:
    void setState(Direction dr);
    void SetPage(PageDirection pdr);
    KonsoldaGoster(Yonetici* yonetici);
    void YoneticiYazdirma();
    void SecilenSatirYazdirma(int x, int y);
    int RandomSecilenDugumGoster();
    void YoneticiDugumSilme();
    void RandomDugumSilme (int randomIndex);
};

#endif