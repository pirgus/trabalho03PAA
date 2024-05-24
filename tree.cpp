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

void binaryTree::insertIter(int key){
    node *newNode = new node; // pq fazer esse new? nao posso só criar o ponteiro e danese?
    newNode->data = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    if(isEmpty()){
        construir_count++;
        root = newNode;
    }
    else{
        node *current = root;
        node *parent;
        while(true){
            parent = current;
            if(newNode->data > current->data){ // se é maior, tem que inserir na direita
                construir_count++;
                current = current->right;
                if(current == nullptr){ // achou nó vazio, pode inserir
                    parent->right = newNode;
                    return;
                } // se nao for vazio, continua o while
            }
            else{ // é menor, tem que inserir na esquerda
                construir_count++;
                current = current->left;
                if(current == nullptr){ // achou nó vazio, pode inserir
                    parent->left = newNode;
                    return;
                } // se nao for vazio, continua o while
            }
        }
    }
}

node* binaryTree::insertRecur(node *root, int key){
    if(root == nullptr){
        construir_count++;
        node *newNode = new node;
        newNode->data = key;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }
    else{
        if(key > root->data){
            construir_count++;
            root->right = insertRecur(root->right, key);
        }
        else{
            construir_count++;
            root->left = insertRecur(root->left, key);
        }
        return root;
    }
}

node* binaryTree::searchRecursive(node *root, int key){
    node *current = root;
    if(current == nullptr){
        consulta_count++;
        return nullptr;
    }
    else if(current->data == key){
        consulta_count++;
        return current;
    }
    else if(key > current->data){
        consulta_count++;
        return searchRecursive(current->right, key);
    }
    else{
        consulta_count++;
        return searchRecursive(current->left, key);
    }
}

node* binaryTree::searchIterative(int key){
     node *current = root;
     while(current != nullptr){
         if(current->data == key){
            consulta_count++;
            return current;
         }
         else if(key > current->data) {
             consulta_count++;
             current = current->right;
         }
         else{
             consulta_count++;
             current = current->left;
         }
     }
     return current;
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
