#include "Btree.h"

BTree::BTree() {
    m_root = new Node();
}
void BTree::addData(int data) {
    addDataHelper(m_root, data);
}
void BTree::display() {
    displayHelper(m_root);
}
void BTree::addDataHelper(Node *root, int data) {
    Node *node = root->addData(data);
    if (node) {
        addDataHelper(node, data);
    }
}
void BTree::displayHelper(Node *root) {
    root->display();
}