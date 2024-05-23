//
// Created by pirgus on 23/05/24.
//
#ifndef TREE_H
#define TREE_H

struct node{
    int data;
    node* left;
    node* right;
};

class binaryTree{

public:
    node *root;
    binaryTree();
    ~binaryTree();
    bool isEmpty();
    void insert(int key);
    node *removeNode(int key); // ainda nao implementei
    node *minValueNode(node *node); // ainda nao implementei
    node* searchRecursive(int key);
    node* searchIterative(int key);
    void destroyTree();
    void printTree(const node *root, int space);
};
#endif //TREE_H
