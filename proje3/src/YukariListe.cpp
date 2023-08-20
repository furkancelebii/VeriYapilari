#include "YukariListe.hpp"
#include "AsagiListe.hpp" 

YukariListe::YukariListe() : head(nullptr), asagiListPointer(nullptr) {}

void YukariListe::ekle(int value) {
    Node* yeniDugum = new Node(value);
    yeniDugum->ileri = head;
    head = yeniDugum;
}

void YukariListe::veriDegis(AsagiListe& digerList) {
    Node* temp = head;
    head = digerList.getHead();
    digerList.setHead(temp);
}

void YukariListe::tersCevir() {
    Node* onceki = nullptr;
    Node* konum = head;
    Node* ileri = nullptr;

    while (konum != nullptr) {
        ileri = konum->ileri;
        konum->ileri = onceki;
        onceki = konum;
        konum = ileri;
    }

    head = onceki;
}

Node* YukariListe::getHead() const {
    return head;
}

void YukariListe::setHead(Node* newHead) {
    head = newHead;
}