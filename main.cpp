//
// Created by pirgus on 23/05/24.
//
#include <iostream>
#include "tree.hpp"
#include <cstdlib>

void clearScreen() {
    std::system("clear");
}

int main(){
    binaryTree tree;
    char opc = 's';
    while(opc != 'n') {
        int key;
        std::cout << "Digite um número para inserir na árvore: \n";
        std::cin >> key;
        tree.insert(key);

        std::cout << "Deseja inserir mais um número? (s/n)\n";
        std::cin >> opc;
        clearScreen();
    }
    //
    // tree.removeNode(10);
    tree.printTree(tree.root, 0);

    return 0;
}