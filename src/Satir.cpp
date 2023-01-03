#include "Satir.hpp"
#include "ConsolePosition.hpp"

SatirDugum* Satir::SiraninOncesiniBul(int index){
    if (index < 0 || index > size) throw "Veri Bulunamadı";
    SatirDugum *prv = head;
    int i = 1;
    for (SatirDugum*itr = head; itr->next != NULL && i != index; itr = itr->next, i++) {
        prv = prv->next;
    }
    return prv;
}

Satir::Satir() {
    head = NULL;
    size = 0;
}
int Satir::Count()const {
    return size;
}
bool Satir::isEmpty()const {
    return size == 0;
}
void Satir::ekle(const int& item) {
    arayaEkle(size, item);
}
void Satir::arayaEkle(int index, const int& item) {
    if (index < 0 || index > size) throw "Gecersiz Sira Değeri";
    if (index == 0) {
        head = new SatirDugum(item, head);
        if (head->next != NULL) head->next->prev = head;
    } else {
        SatirDugum *prv = SiraninOncesiniBul(index);
        prv->next = new SatirDugum(item, prv->next, prv);
        if (prv->next->next != NULL)
            prv->next->next->prev = prv->next;
    }
    size++;
}
const int& Satir::first() {
    if (isEmpty()) throw "Veri Bulunamadı";
    return head->data;
}
const int& Satir::last(){
    if (isEmpty()) throw "Veri Bulunamadı";
    return SiraninOncesiniBul(size)->data;
}
int Satir::indexOf(const int& item){
    int index = 0;
    for (SatirDugum *itr = head; itr != NULL; itr = itr->next) {
        if (itr->data == item) return index;
        index++;
    }
    throw "Veri Bulunamadı";
}
void Satir::sil(const int& item) {
    int index = indexOf(item);
    removeAt(index);
}
void Satir::removeAt(int index) {
    if (index < 0 || index >= size) throw "Gecersiz Sira Değeri";
    SatirDugum *del;
    if (index == 0) {
        del = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
    } else {
        SatirDugum *prv = SiraninOncesiniBul(index);
        del = prv->next;
        prv->next = del->next;
        if (del->next != NULL)
            del->next->prev = prv;
    }
    size--;
    delete del;
}
bool Satir::bul(const int& item) {
    for (SatirDugum *itr = head; itr != NULL; itr = itr->next) {
        if (itr->data == item) return true;
    }
    return false;
}
void Satir::tersCevir() {
    for (SatirDugum *itr = head; itr != NULL;) {
        SatirDugum *tmp = itr->next;
        itr->next = itr->prev;
        itr->prev = tmp;
        if (tmp == NULL) {
            head = itr;
            break;
        }
        itr = tmp;
    }
}
const int& Satir::elementAt(int index){
    if (index < 0 || index >= size) throw "Veri Bulunamadı";
    if (index == 0) return head->data;
    return SiraninOncesiniBul(index)->next->data;
}
void Satir::temizle() {
    while (!isEmpty())
        removeAt(0);
}
void Satir::dugumPozisyonunaGoreTersSiraYazdir(int index){
    if (index < 0 || index >= size)throw "Veri Bulunamadı";
    for (SatirDugum *itr = SiraninOncesiniBul(index + 1); itr != NULL; itr = itr->prev) {
        
        cout << itr->data << " <-> ";
    }
    cout << endl;
}
void Satir::tersSiraYazdir() {
    dugumPozisyonunaGoreTersSiraYazdir(size - 1);
}
void Satir::satirYazdir(int x,int y){
    int yIndex=y; 
    ConsolePosition.gotoxy(x,yIndex);
    cout<<"^^^^^^^^\n"; 
     for (SatirDugum *itr = this->head; itr != NULL; itr = itr->next) {
      
        ConsolePosition.gotoxy(x,++yIndex);
        cout<<itr<<"\n";
        ConsolePosition.gotoxy(x,++yIndex);
        cout<<"------------\n";
        ConsolePosition.gotoxy(x,++yIndex);
        cout<<"|"<<setw(5)<<itr->data<<setw(5)<<"|"<<endl;
        ConsolePosition.gotoxy(x,++yIndex);
        cout<<"------------\n";
        ConsolePosition.gotoxy(x,++yIndex);
        cout<<"|"<<itr->next<<setw(3)<<"|\n";
        ConsolePosition.gotoxy(x,++yIndex);
        cout<<"------------\n\n";
    }
}
Satir::~Satir() {
    temizle();
}