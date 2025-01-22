#include <iostream>

#include "BTree.h"

using namespace std;

bool is_number(const std::string &);

int main(int argc, char **argv) {
    BTree tree;
    std::string input;
    while (true) {
        cout << "Enter a number to add: ";
        cin >> input;
        if (input == "q") {
            break;
        }
        if (!is_number(input)) {
            cout << "You entered '" << input << "' which is not a valid number" << endl;
            continue;
        }
        cout << "-----------------------------------------" << endl;
        tree.addData(atoi(input.c_str()));
        tree.displayTree();
    }
    /*tree.addData(5);
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
    tree.addData(16);
    cout << "-----------------------------------------" << endl;
    tree.displayTree();
    tree.addData(17);
    cout << "-----------------------------------------" << endl;
    tree.displayTree();*/
    return 0;
}

bool is_number(const std::string& s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}