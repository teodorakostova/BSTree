#include <iostream>
#include "BSTree.h"
using namespace std;

BSTree::BSTree() : root(NULL) {
//    int k;
//    while (cin >> k)
//        insert(k, root);
}

bool BSTree::Search(int data) const {
    return search(data, root);
}

bool BSTree::search(int data, Node* p) const {
    if (p->data == data)
        return true;
    if (p->pLeft && p->data > data)
        return search(data, p->pLeft);
    else if (p->pRight)
        return search(data, p->pRight);

    return false;
}

void BSTree::insert(int data, Node* &p) {
    if (!p) {
        p = new Node;
        p->data = data;
        p->pLeft = p->pRight = NULL;
    } else {
        insert(data, data < p->data ? p->pLeft : p->pRight);
    }
}

void BSTree::Insert(int data) {
    insert(data, root);
}

Node* BSTree::find_min(Node* r) const {
    if (!r->pLeft)
        return r;
    find_min(r->pLeft);
}

bool BSTree::remove(int data, Node*& r) {
    if (!r)
        return false;
    if (r->data < data) {
        return remove(data, r->pRight);
    } else if (r->data > data) {
        return remove(data, r->pLeft);
    } else {
        if (!r->pLeft && !r->pRight) {
            delete r;
            r = NULL;
        } else if (r->pLeft && r->pRight) {
            r->data = find_min(r->pRight)->data;
        } else {
            Node* old = r;
            r = r->pLeft ? r->pLeft : r->pRight;
            delete old;
        }
        return true;
    }
}

bool BSTree::Remove(int data) {
    return remove(data, root);
}

void BSTree::print(const Node* node, ostream& out = cout) const {
    if (node) {
        print(node->pLeft, out);
        out << node->data << " ";
        print(node->pRight, out);
    }
}

void BSTree::Print(ostream& out = cout) const {
    print(root, out);
}

int main() {
    BSTree* bt = new BSTree();

    int arr[] = {5, 19, 21, 25, 2, -4, 3, 9};
    int size = sizeof(arr)/sizeof(int);
    for (int i = 0; i < size; i++) {
        bt->Insert(arr[i]);
    }
    bt->Remove(3);
    bt->Print(cout);

    cout << boolalpha << bt->Search(4) << endl;

	cin.get();
    return 0;
}
