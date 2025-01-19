#include <iostream>
#include <algorithm>

#include "Node.h"

Node::Node() {
    children = {};
    m_data = {};
    parent = NULL;
}
Node::Node(Node *p, int val1, int val2) {
    children = {};
    m_data = {val1, val2};
    parent = p;
}
Node::Node(int data, Node* leftChild, Node* rightChild) {
    children = {};
    m_data = {};
    parent = NULL;
    m_data.push_back(data);
    children.push_back(leftChild);
    children.push_back(rightChild);
}
Node::~Node() {
    children.clear();
    std::vector<Node*>().swap(children);
    m_data.clear();
    std::vector<int>().swap(m_data);
    delete parent;
}
Node* Node::addData(int data) {
    if (children.size() > 0) {
        int index = 0;
        for (int split : m_data) {
            if (data > split) {
                index++;
            } else {
                break;
            }
        }
        return children[index];
    }
    if (!isFull()) {
        m_data.push_back(data);
        std::sort(m_data.begin(), m_data.end());
        return 0;
    } else {
        std::vector<int> temp_vec;
        temp_vec = m_data;
        temp_vec.push_back(data);
        std::sort(m_data.begin(), m_data.end());
        int split = temp_vec[2];
        int numOfLeftChildren = getNumOfLeftChild(split);
        Node *leftSibling = createLeftSibling(numOfLeftChildren);
        leftSibling->m_data.push_back(temp_vec[0]);
        leftSibling->m_data.push_back(temp_vec[1]);
        m_data = {};
        m_data.push_back(temp_vec[3]);
        m_data.push_back(temp_vec[4]);
        if (children.size() > 0) {
            children.erase(children.begin(), children.begin()+numOfLeftChildren+1);
        }
        if (!parent) {
            Node* newParent = new Node(split, leftSibling, this);
            parent = newParent;
            leftSibling->parent = newParent;
            return parent;
        } else {
            leftSibling->parent = parent;
        }
        return 0;
    }
}
void Node::fixPointers() {
    return;
}
bool Node::isFull() {
    return m_data.size()==maxData;
}
void Node::display() {
    int i;
    if (children.empty()) {
        for (int data : m_data) {
            std::cout << data << std::endl;
        }
    } else {
        for (int i = 0; i < children.size(); i++) {
            if (i>0) {
                std::cout << m_data[i-1] << std::endl;
            }
            children[i]->display();
        }
    }
}
Node* Node::getParent() {
    return parent;
}
bool Node::isRightmost() {
    if (parent == NULL) return true;
    return parent->children[parent->children.size()-1] == this;
}
void Node::displayTree(int space) {
    for (int i = 0; i < space; i++) {
        if (i % 4 == 0) {
            std::cout << "|";
        } else {
            std::cout << " ";
        }
    }
    std::cout << "|--";
    for (int data : m_data) {
        std::cout << data << " ";
    }
    std::cout << std::endl;
    for (auto child : children) {
        child->displayTree(space+3);
    }
}
int Node::getNumOfLeftChild(int split) {
    int ret = 0;
    for (auto child : children) {
        if (child->m_data[0] < split) {
            ret++;
        } else {
            break;
        }
    }
    return ret;
}
Node* Node::createLeftSibling(int numOfChildren) {
    Node* leftSibling = new Node();
    for (int i = 0; i < numOfChildren; i++) {
        leftSibling->children.push_back(children[i]);
    }
    return leftSibling;
}