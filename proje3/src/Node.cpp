#include "Node.hpp"

// listeyi ters çevirebilmek için fonksiyon tanımlıyoruz
Node* tersListeNode(Node* head) {
    Node* onceki = nullptr;
    Node* konum = head;
    Node* ileri = nullptr;

    while (konum != nullptr) {
        ileri = konum->ileri;
        konum->ileri = onceki;
        onceki = konum;
        konum = ileri;
    }

    return onceki;
}