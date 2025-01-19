#include <vector>

#define MAX_DATA_SIZE 4

class Node {
    public:
        Node();
        Node(Node*, int, int);
        Node(int, Node*, Node*);
        ~Node();
        Node* addData(int);
        Node* getParent();
        void display();
        void displayTree(int);
    private:
        const int maxData = MAX_DATA_SIZE;
        const int minData = maxData/2;
        std::vector<Node*> children;
        Node *parent;
        std::vector<int> m_data;
        void addNewChild();
        void fixPointers();
        bool isFull();
        bool isRightmost();
        int  getNumOfLeftChild(int);
        Node* createLeftSibling(int);
        bool comp(int a, int b) {
            return a < b;
        }
};