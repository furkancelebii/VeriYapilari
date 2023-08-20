#ifndef YUKARILISTE_HPP
#define YUKARILISTE_HPP

#include "Node.hpp"

//ileriye bildirim veriyoruz
class AsagiListe;

class YukariListe {
private:
    Node* head;
    AsagiListe* asagiListPointer; //Asa�� do�ru olan listenin pointer tan�m�

public:
    YukariListe();
    void ekle(int value);
    void veriDegis(AsagiListe& digerList);
    void tersCevir();
    Node* getHead() const;
    void setHead(Node* newHead);
};

#endif
