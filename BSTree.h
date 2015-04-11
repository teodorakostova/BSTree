#pragma once
#include <iostream>

struct Node {
    int data;
    Node* pLeft;
    Node* pRight;
};

class BSTree {
public:
    BSTree();
    bool Search(int) const;
    void Insert(int);
    void Print(std::ostream&) const;
    bool Remove(int);

private:
    void insert(int, Node*&);
    bool search(int, Node*) const;
    bool remove(int, Node*&);
    void print(const Node*, std::ostream&) const;
    Node* find_min(Node*) const;

    Node* root;
};