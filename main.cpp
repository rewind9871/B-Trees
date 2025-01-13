#include <iostream>

#include "BTree.h"

using namespace std;

int main(int argc, char **argv) {
    BTree tree;
    tree.addData(5);
    tree.addData(4);
    tree.addData(9);
    tree.addData(3);
    tree.addData(10);
    tree.addData(15);
    tree.display();
    return 0;
}