#include "Yonetici.hpp"
YoneticiDugum* Yonetici::SiraninOncesiniBul(int index) {
    if (index < 0 || index > size) throw "Veri Bulunamadi";
    YoneticiDugum *prv = head;
    int i = 1;
    for (YoneticiDugum *itr = head; itr->next != NULL && i != index; itr = itr->next, i++) {
        prv = prv->next;
    }
    return prv;
}
YoneticiDugum* Yonetici::SiraBul(int index){
    if (index < 0 || index >= size) throw "Veri Bulunamadi";
    return this->SiraninOncesiniBul(index + 1);

}
Yonetici::Yonetici() {
    head = NULL;
    size = 0;
}
int Yonetici::Count()const {
    return size;
}
bool Yonetici::isEmpty()const {
    return size == 0;
}
void Yonetici::ekle(Satir*& item) {
    arayaEkle(size, item);
}
void Yonetici::arayaEkle(int index, Satir*& item) {
    if (index < 0 || index > size) throw "Araligin Disinda Bir Deger";
    if (index == 0) {
        head = new YoneticiDugum(item, head);
        if (head->next != NULL) head->next->prev = head;
    } else {
        YoneticiDugum *prv = SiraninOncesiniBul(index);
        prv->next = new YoneticiDugum(item, prv->next, prv);
        if (prv->next->next != NULL)
            prv->next->next->prev = prv->next;
    }
    size++;
}
Satir*& Yonetici::first(){
    if (isEmpty()) throw "Veri Bulunamadi";
    return head->data;
}
Satir*& Yonetici::last(){
    if (isEmpty()) throw "Veri Bulunamadi";
    return SiraninOncesiniBul(size)->data;
}
int Yonetici::indexOf(Satir*& item){
    int index = 0;
    for (YoneticiDugum *itr = head; itr != NULL; itr = itr->next) {
        if (itr->data == item) return index;
        index++;
    }
    throw "Veri Bulunamadi";
}
void Yonetici::sil(Satir*& item) {
    int index = indexOf(item);
    removeAt(index);
}
void Yonetici::randomSatirSilme(int index, int inlineIndex){

    int count = this->Count();
    if (index < 0 || index >= count)
		throw "Sinirlarin Disinda Bir Deger";

    Satir* satir = this->elementAt(index);

    satir->removeAt(inlineIndex);
    ortalamaHesapla(index);

}
void Yonetici::ortalamaHesapla(int index) {
    YoneticiDugum* yoneticiDugum = this->SiraBul(index);

    if (yoneticiDugum == NULL) {

        throw "hata";
    }
    double total = 0;
    if (yoneticiDugum->data->isEmpty()) {

        yoneticiDugum->ortalama = total;
        return;
    }
    int count = yoneticiDugum->data->Count();
    for (int i = 0; i < count; ++i) {
        total += yoneticiDugum->data->elementAt(i);
    }
    yoneticiDugum->ortalama = total / count;
}
int Yonetici::randomUretici(int index){
    int count = this->Count();
    if (index < 0 || index >= count)
        throw "Sinirlarin Disinda Bir Deger";
    srand(time(NULL));
    Satir* satir = this->elementAt(index);
    int range = satir->Count();
    if (range == 0) {
        throw "Veri Bulunamadi";
    }
    int inlineIndex = rand() % range;
    return inlineIndex;
}
void Yonetici::removeAt(int index) {
    if (index < 0 || index >= size) throw "Araligin Disinda Bir Deger";
    YoneticiDugum *del;
    if (index == 0) {
        del = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
    } else {
        YoneticiDugum *prv = SiraninOncesiniBul(index);
        del = prv->next;
        prv->next = del->next;
        if (del->next != NULL)
            del->next->prev = prv;
    }
    size--;
    delete del;
}

void Yonetici::dugumTasi(int from, int to){
    if (from < 0 || from >= size) throw "Sinirlarin Disinda Bir Deger";
    YoneticiDugum *del;
    if (from == 0) {
        del = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
    } else {
        YoneticiDugum *prv = SiraninOncesiniBul(from);
        del = prv->next;
        prv->next = del->next;
        if (del->next != NULL)
            del->next->prev = prv;
    }
    size--;
    if (to < 0 || to > size) throw "Sinirlarin Disinda Bir Deger";
    if (to == 0) {

        del->next = head;
        del->prev = NULL;
        head = del;
        if (head->next != NULL) head->next->prev = head;
    } else {
        YoneticiDugum *prv = SiraninOncesiniBul(to);

        del->next = prv->next;
        del->prev = prv;
        prv->next = del;
        if (prv->next->next != NULL)
            prv->next->next->prev = prv->next;
    }
    size++;
}
bool Yonetici::bul(Satir*& item) {
    for (YoneticiDugum *itr = head; itr != NULL; itr = itr->next) {
        if (itr->data == item) return true;
    }
    return false;
}
void Yonetici::tersCevir() {
    for (YoneticiDugum *itr = head; itr != NULL;) {
        YoneticiDugum *tmp = itr->next;
        itr->next = itr->prev;
        itr->prev = tmp;
        if (tmp == NULL) {
            head = itr;
            break;
        }
        itr = tmp;
    }
}
void Yonetici::ortalamaSirala() {
    if (this->size <= 1)
        return;
    for (int step = 0; step < size; ++step) {
        for (int i = 0; i < size - step - 1; ++i) {
            YoneticiDugum *tmp = this->SiraBul(i);
            YoneticiDugum *tmp2 = tmp->next;
            if (tmp->ortalama > tmp2->ortalama) {
                this->dugumTasi(i + 1, i);
            }
        }
    }

}
Satir*& Yonetici::elementAt(int index) {
    if (index < 0 || index >= size) throw "Veri Bulunamadi";
    if (index == 0) return head->data;
    return SiraninOncesiniBul(index)->next->data;
}
void Yonetici::temizle() {
    while (!isEmpty())
        removeAt(0);
}
void Yonetici::printIndex(int index, int x, int y) {
    YoneticiDugum *node = this->SiraBul(index);
    ConsolePosition.gotoxy(x, y);
    cout << fixed << setprecision(2);
    cout << node << "\n";
    ConsolePosition.gotoxy(x, y + 1);
    cout << "-----------\n";
    ConsolePosition.gotoxy(x, y + 2);
    cout << "|" << node->prev << setw(3) << "|\n";
    ConsolePosition.gotoxy(x, y + 3);
    cout << "-----------\n";
    ConsolePosition.gotoxy(x, y + 4);
    cout << "|" << setw(3) << node->ortalama << setw(5) << "|" << endl;
    ConsolePosition.gotoxy(x, y + 5);
    cout << "-----------\n";
    ConsolePosition.gotoxy(x, y + 6);
    cout << "|" << node->next << setw(3) << "|\n";
    ConsolePosition.gotoxy(x, y + 7);
    cout << "-----------\n\n";

}

Yonetici::~Yonetici() {
    temizle();
}