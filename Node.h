#include <vector>

#define MAX_DATA_SIZE 4

class Node {
    public:
        Node();
        Node(Node*, int, int);
        ~Node();
        Node* addData(int);
        void display();
    private:
        const int maxData = MAX_DATA_SIZE;
        const int minData = maxData/2;
        std::vector<Node*> children;
        Node *parent;
        std::vector<int> m_data;
        void addNewChild();
        bool comp(int a, int b) {
            return a < b;
        }
};