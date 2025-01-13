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
Node::~Node() {
    children.clear();
    std::vector<Node*>().swap(children);
    m_data.clear();
    std::vector<int>().swap(m_data);
    delete parent;
}
Node* Node::addData(int data) {
    if(children.empty()) {
        m_data.push_back(data);
        std::sort(m_data.begin(), m_data.end());
        if (m_data.size() > maxData) {
            if(!parent && children.empty()) {
                children.push_back(new Node(this, m_data[0], m_data[1]));
                children.push_back(new Node(this, m_data[3], m_data[4]));
                m_data.erase(m_data.begin()+3, m_data.begin()+5);
                m_data.erase(m_data.begin(), m_data.begin()+2);
            } else { //Do not allow additions other than an unfull root currently
                std::remove(m_data.begin(), m_data.end(), data);
            }
        }
        return 0;
    } else {
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