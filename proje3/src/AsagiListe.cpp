#include "AsagiListe.hpp"

AsagiListe::AsagiListe() : head(nullptr) {}

void AsagiListe::ekle(int value) {
    Node* yeniDugum = new Node(value);
    yeniDugum->ileri = head;
    head = yeniDugum;
}

Node* AsagiListe::getHead() const {
    return head;
}

void AsagiListe::setHead(Node* newHead) {
    head = newHead;
}
