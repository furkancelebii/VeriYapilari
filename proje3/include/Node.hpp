#ifndef NODE_HPP
#define NODE_HPP

struct Node {
    int veri;
    Node* ileri;
    Node(int value) : veri(value), ileri(nullptr) {}
};

// Listeyi ters �evirebilmek i�in tan�mlama yap�yoruz
Node* tersListeNode(Node* head);

#endif

