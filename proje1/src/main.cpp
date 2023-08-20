#include <cstdlib>
#include "Satir.hpp"
#include "Yonetici.hpp"
#include "OkuEkle.hpp"
#include "KonsoldaGoster.hpp"
using namespace std;
int main(int argc, char** argv) {
    OkuEkle * readingFile = new OkuEkle("veriler.txt");
    Yonetici *yonetici = readingFile->YoneticiDoldur();
    KonsoldaGoster *console = new KonsoldaGoster(yonetici);
    yonetici->ortalamaSirala();
    string karakter = "";
    do {
        console->YoneticiYazdirma();
        cin>>karakter;
        if (karakter == "c") {
            Direction direction = up;
            console->setState(direction);
        } 
		else if (karakter == "z") {
            Direction direction = down;
            console->setState(direction);
        } 
		else if (karakter == "k") {
            int randomIndex = 0;
            try {
                randomIndex = console->RandomSecilenDugumGoster();
            } catch (...) {
                continue;
            }
            cin>>karakter;
            if (karakter == "k") {
                console->RandomDugumSilme(randomIndex);
                yonetici->ortalamaSirala();
            }
        } 
		else if (karakter == "p") {
            console->YoneticiDugumSilme();
        } 
		else if (karakter == "d") {
            console->SetPage(upPage);
        } 
		else if (karakter == "a") {
            console->SetPage(downPage);
        }
    } while (karakter != "q");
    return 0;
}