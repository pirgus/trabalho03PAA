#include <iostream>
#include "tree.hpp"

binaryTree::binaryTree(){
    root = nullptr;
}

binaryTree::~binaryTree(){
//     destroyTree();
}

bool binaryTree::isEmpty(){
    return root == nullptr;
}

void binaryTree::insert(int key){
    node *newNode = new node; // pq fazer esse new? nao posso só criar o ponteiro e danese?
    newNode->data = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    if(isEmpty()){
        root = newNode;
    }
    else{
        node *current = root;
        node *parent;
        while(true){
            parent = current;
            if(newNode->data > current->data){ // se é maior, tem que inserir na direita
                current = current->right;
                if(current == nullptr){ // achou nó vazio, pode inserir
                    parent->right = newNode;
                    return;
                } // se nao for vazio, continua o while
            }
            else{ // é menor, tem que inserir na esquerda
                current = current->left;
                if(current == nullptr){ // achou nó vazio, pode inserir
                    parent->left = newNode;
                    return;
                } // se nao for vazio, continua o while
            }
        }
    }
}

node* binaryTree::searchRecursive(node *root, int key){
    node *current = root;
    if(current == nullptr){
        return nullptr;
    }
    else if(current->data == key){
        return current;
    }
    else if(key > current->data){
        return searchRecursive(current->right, key);
    }
    else{
        return searchRecursive(current->left, key);
    }
}

node* binaryTree::searchIterative(int key){
     node *current = root;
     while(current != nullptr){
         if(current->data == key){
            return current;
         }
         else if(key > current->data) {
             current = current->right;
         }
         else{
             current = current->left;
         }
     }
}

void binaryTree::printTree(const node *root, int space)
{
    const int count = 10; // Define o número de espaços para cada nível da árvore
    if (root == nullptr) // Se a árvore estiver vazia, retorna
        return;

    space += count; // Aumenta a distância entre níveis

    printTree(root->right, space); // Processa o subárvore direita primeiro

    std::cout << std::endl;
    for (int i = count; i < space; i++)
        std::cout << " "; // Imprime os espaços antes do nó
    std::cout << root->data << "\n"; // Imprime o valor do nó

    printTree(root->left, space); // Processa a subárvore esquerda
}
