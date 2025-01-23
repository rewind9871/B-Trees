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
bool BTree::isValidTree() {
    return m_root->isValidNode(INT_MIN, INT_MAX);
}
void BTree::addDataHelper(Node *root, int data) {
    Node *node = root->addData(data);
    if (node != NULL && node->getParent() == NULL) {
        m_root = node;
    } else if (node) {
        addDataHelper(node, data);
    }
}
void BTree::displayHelper(Node *root) {
    root->display();
}
void BTree::displayTree() {
    m_root->displayTree(0);
}