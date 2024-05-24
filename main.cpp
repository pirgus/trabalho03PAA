//
// Created by pirgus on 23/05/24.
//
#include <iostream>
#include "tree.hpp"
#include <chrono>
#include <fstream>

int main(int argc, char const *argv[]){

    std::string n_construir = argv[1];
    char rec_or_iter = argv[2][0];
    std::string construir_path = "./Construir/" + n_construir + ".txt";
    std::string consulta_path = "./Consultar/" + n_construir + ".txt";

    std::ifstream construir_file(construir_path);
    std::ifstream consulta_file(consulta_path);

    binaryTree tree;




    if(rec_or_iter == 'r') {
        int a;
        auto start = std::chrono::high_resolution_clock::now();
        // realizar construcao da arvore
        while(construir_file >> a) {
            tree.root = tree.insertRecur(tree.root, a);
            // std::cout << "valor inserido na árvore: " << a << std::endl;
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration = end - start;
        std::cout << "tempo de execução da construcao rec = " << duration.count() << " ms\n";
        std::cout << "qtd de comparacoes na construcao rec = " << tree.construir_count << " ";


        // tree.printTree(tree.root, 0);
        // realizar consultas
        start = std::chrono::high_resolution_clock::now();
        while(consulta_file >> a) {
            node *search;
            search = tree.searchRecursive(tree.root, a);
            // if(search != nullptr) {
            //     std::cout << "Numero encontrado: " << search->data << std::endl;
            // }
            // else {
            //     std::cout << "Numero " << a << " nao encontrado\n";
            // }
        }
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "tempo de execução da consulta rec = " << duration.count() << " ms\n";
        std::cout << "qtd de comparacoes na consulta rec = " << tree.consulta_count << std::endl;

    }
    else if(rec_or_iter == 't') {
        int a;

        auto start = std::chrono::high_resolution_clock::now();
        // construcao da arvore
        while(construir_file >> a) {
            tree.insertIter(a);
            // std::cout << "valor inserido na árvore: " << a << std::endl;
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration = end - start;
        std::cout << "tempo de execução da construcao iter = " << duration.count() << " ms\n";
        std::cout << "qtd de comparacoes na construcao iter = " << tree.construir_count << std::endl;

        // tree.printTree(tree.root, 0);

        start = std::chrono::high_resolution_clock::now();
        // consultas na arvore
        while(consulta_file >> a) {
            node *search;
            search = tree.searchIterative(a);
            // if(search != nullptr) {
            //     std::cout << "Número encontrado: " << search->data << std::endl;
            // }
            // else {
            //     std::cout << "Numero " << a << "nao encontrado\n";
            // }
        }
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "tempo de execução da consulta iter = " << duration.count() << " ms\n";
        std::cout << "qtd de comparacoes na consulta iter = " << tree.consulta_count << std::endl;

    }
    else {
        std::cout << "Operação inválida\n";
        return -1;
    }


    construir_file.close();
    consulta_file.close();
    return 0;
}