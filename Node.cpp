#include <iostream>
#include <algorithm>

#include "Node.h"

Node::Node() {
    children = {};
    m_data = {};
    parent = NULL;
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
        std::sort(temp_vec.begin(), temp_vec.end());
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
        if (!parent) { //Create a new root node
            Node* newParent = new Node(split, leftSibling, this);
            parent = newParent;
            leftSibling->parent = newParent;
            return parent;
        } else { //Push data upwards and add left sibling
            leftSibling->parent = parent;
            return parent->addDataUpwards(split, leftSibling, this);
        }
        return 0;
    }
}
Node* Node::addDataUpwards(int data, Node* leftSibling, Node* rightSibling) {
    if (!isFull()) {
        m_data.push_back(data);
        std::sort(m_data.begin(), m_data.end());
        std::vector<Node *>::iterator it = children.begin();
        while (it != children.end()) {
            if (*it == rightSibling) {
                children.insert(it, leftSibling);
                break;
            }
            it++;
        }
        return 0;
    } else {
        std::vector<int> temp_vec;
        temp_vec = m_data;
        temp_vec.push_back(data);
        std::sort(m_data.begin(), m_data.end());
        int split = temp_vec[2];
        int numOfLeftChildren = getNumOfLeftChild(split);
        Node *newLeftSibling = createLeftSibling(numOfLeftChildren);
        newLeftSibling->m_data.push_back(temp_vec[0]);
        newLeftSibling->m_data.push_back(temp_vec[1]);
        m_data = {};
        m_data.push_back(temp_vec[3]);
        m_data.push_back(temp_vec[4]);
        if (children.size() > 0) {
            children.erase(children.begin(), children.begin()+numOfLeftChildren);
        }
        std::vector<Node *>::iterator it = newLeftSibling->children.begin();
        while (it != newLeftSibling->children.end()) {
            if (*it == rightSibling) {
                newLeftSibling->children.insert(it, leftSibling);
                break;
            }
            it++;
        }
        if (it == newLeftSibling->children.end()) {
            it = children.begin();
            while (it != children.end()) {
                if (*it == rightSibling) {
                    children.insert(it, leftSibling);
                    break;
                }
                it++;
            }
        }
        if (!parent) { //Create a new root node
            Node* newParent = new Node(split, newLeftSibling, this);
            parent = newParent;
            newLeftSibling->parent = newParent;
            return parent;
        } else { //Push data upwards and add left sibling
            newLeftSibling->parent = parent;
            return parent->addDataUpwards(split, newLeftSibling, this);
        }
        return 0;
    }
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
void Node::displayTree(int space) {
    for (int i = 0; i < space; i++) {
        if (i % 3 == 0) {
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
bool Node::isValidNode(int min, int max) {
    bool ret = true;
    for (auto data: m_data) {
        ret = ret && (data >= min) && (data <= max);
        if (!ret) {
            return ret;
        }
    }
    for (int i = 0; i < children.size(); i++) {
        int newMin = ((i-1) < 0 ? INT_MIN : m_data[i-1]);
        /*if ((i-1) < 0) {
            newMin = INT_MIN;
        } else {
            newMin = m_data[i-1];
        }*/
        int newMax = (i == m_data.size() ? INT_MAX : m_data[i]);
        /*if (i == m_data.size()) {
            newMax = INT_MAX;
        } else {
            newMax = m_data[i];
        }*/
        ret = ret && children[i]->isValidNode(newMin, newMax);
        if (!ret) {
            return ret;
        }
    }
    return ret;
}