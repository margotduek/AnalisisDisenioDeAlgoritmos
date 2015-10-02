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

using namespace std;

int main(int argc, const char * argv[]) {
    
    AVLTree<int> numeros;
    BTree<int, 5> * tree = new BTree<int, 5>();
    int random;
    int array[10];
    
    for(int i=0; i<100000; i++){
        random = rand();
        
        numeros.insert(random);
        tree->insert(random);
        //Insertar aquí los inserta (redundancia :P) de los otros árboles
        if(i<10)
        array[i] = random;
    }
    
    std::cout<<"hola"<<std::endl;
    
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
    }
    
    
       
    return 0;
}
