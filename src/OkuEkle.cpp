#include "OkuEkle.hpp"
Yonetici* OkuEkle::YoneticiDoldur(){
    readLine();
    Yonetici *tmp=new Yonetici();
    int count=satirSayaci();
    for(int i=0;i<count;++i){
        tmp->ekle(this->lines[i]);
    }
    return tmp;
}
OkuEkle::OkuEkle(std::string fileName) {
    this->fileName = fileName;
    int numlines = satirSayaci();
    this->lines = new Satir*[numlines];
    for (int i = 0; i < numlines; i++) {
        this->lines[i] = new Satir();
    }
}
int OkuEkle::satirSayaci() {
    int counter = 0;
    std::ifstream file(this->fileName);
    std::string unused;
    while (std::getline(file, unused))
        ++counter;
    file.close();
    return counter;
}
void OkuEkle::readLine() {
    std::string token;
    std::ifstream file(this->fileName);
    std::string str;
    int index = 0;
    while (std::getline(file, token)) {
        std::istringstream ss(token);

        while (std::getline(ss, str, ' ')) {
            this->lines[index]->ekle(stoi(str));
        }
        index++;
    }
    file.close();
}
OkuEkle::~OkuEkle(){
	if(lines!=0){
		int count =satirSayaci();
		for (int i = 0; i < count; i++){
			if(lines[i]!=0) delete lines[i];
		}
		delete[] lines;
	}
	
}