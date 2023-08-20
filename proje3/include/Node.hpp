#ifndef NODE_HPP
#define NODE_HPP

struct Node {
    int veri;
    Node* ileri;
    Node(int value) : veri(value), ileri(nullptr) {}
};

// Listeyi ters çevirebilmek için tanýmlama yapýyoruz
Node* tersListeNode(Node* head);

#endif

