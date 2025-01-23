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
        bool validTree = tree.isValidTree();
        if (!validTree) {
            printf("Tree layout is not valid!\n");
            return 1;
        }
    }
    return 0;
}

bool is_number(const std::string& s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}