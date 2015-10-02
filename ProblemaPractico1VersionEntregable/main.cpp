//
//  main.cpp
//  Arboles
//
//  Created by Krikor Bisdikian G. on 5/9/15.
//  Copyright © 2015 Krikor Bisdikian G. All rights reserved.
//

#include <iostream>
#include "BinarySTree.h"
#include "AVLTree.h"
#include <chrono>
#include "BTree.h"
#include "RBTree/RBTree.h"
#include "2-3/DosTres.h"

using namespace std;



int main(int argc, const char * argv[]) {

    AVLTree<int> numeros;
    BTree<int, 5> * tree = new BTree<int, 5>();
    RBTree<int> * elRojo = new RBTree<int>();
    DosTres<int>* dostres = new DosTres<int>();
    int random;
    int array[10];

    //std::cout<<"hola1"<<std::endl;


    for(int i=0; i<10000; i++){
        random = rand() % 1000;
        //std::cout<<"hola2"<<std::endl;

        numeros.insert(random);
        //std::cout<<"hola3"<<std::endl;

        tree->insert(random);
        //std::cout<<"hola4"<<std::endl;

        elRojo->RBinsert(random);

        dostres->insert23(random);
        //Insertar aquí los inserta (redundancia :P) de los otros árboles
        if(i<10)
        //std::cout<<"hola5"<<std::endl;

        array[i] = random;
        //std::cout<<"hola6"<<std::endl;

    }

    //std::cout<<"hola"<<std::endl;

     auto begin = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    auto tiempo = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);

    for(int i=0; i<10; i++){
        begin = std::chrono::high_resolution_clock::now();
        numeros.search(array[i]);
        end = std::chrono::high_resolution_clock::now();
        tiempo = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
        cout<<"AVL->numero "<<i<<": tardó "<<tiempo.count()<<endl;

        begin = std::chrono::high_resolution_clock::now();
        tree->search(array[i]);
        end = std::chrono::high_resolution_clock::now();
        tiempo = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
        cout<<"Btree->numero "<<i<<": tardó "<<tiempo.count()<<endl;

        begin = std::chrono::high_resolution_clock::now();
        elRojo->verificarArbol(elRojo);
        end = std::chrono::high_resolution_clock::now();
        tiempo = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
        cout<<"RojiNegro->numero "<<i<<": tardó "<<tiempo.count()<<endl;

        begin = std::chrono::high_resolution_clock::now();
        dostres->isTT();
        end = std::chrono::high_resolution_clock::now();
        tiempo = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
        cout<<"DosTres->numero "<<i<<": tardó "<<tiempo.count()<<endl;
    }



    return 0;
}
