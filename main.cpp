#include <iostream>

#include "BTree.h"

using namespace std;

int main(int argc, char **argv) {
    BTree tree;
    tree.addData(5);
    cout << "-----------------------------------------" << endl;
    tree.displayTree();
    tree.addData(4);
    cout << "-----------------------------------------" << endl;
    tree.displayTree();
    tree.addData(9);
    cout << "-----------------------------------------" << endl;
    tree.displayTree();
    tree.addData(3);
    cout << "-----------------------------------------" << endl;
    tree.displayTree();
    tree.addData(10);
    cout << "-----------------------------------------" << endl;
    tree.displayTree();
    tree.addData(15);
    cout << "-----------------------------------------" << endl;
    tree.displayTree();
    return 0;
}