#include <iostream>

#include "Node.h"

class BTree {
    public:
        BTree();
        void addData(int);
        void display();
        void displayTree();
        bool isValidTree();
    private:
        Node *m_root;
        void addDataHelper(Node *, int);
        void displayHelper(Node *);
};