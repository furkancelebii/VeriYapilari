#ifndef ASAGILISTE_HPP
#define ASAGILISTE_HPP

#include "Node.hpp"

class AsagiListe {
private:
    Node* head;

public:
    AsagiListe();
    void ekle(int value);
    Node* getHead() const;
    void setHead(Node* newHead);
};

#endif
