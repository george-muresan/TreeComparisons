//
//  main.cpp
//  ProjectTwo
//
//  Created by George Muresan on 3/25/19.
//  Copyright © 2019 George Muresan. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <string>
#include "main.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main(int argc, const char * argv[])
{
    
   //string fileName = argv[1];
    string fileName = "/Users/georgemuresan/Downloads/p2_test1.txt";
    ifstream inFile(fileName.c_str());
    int numbers;
    BST_Tree dataBST;
    while(inFile >> numbers)
    {
        dataBST.insert(numbers);
    }
    inFile.clear();
    inFile.ignore(1);
    dataBST.print();
    while(inFile >> numbers)
    {
        dataBST.search(numbers);
    }
    inFile.clear();
    inFile.ignore(1);
    while(inFile >> numbers)
    {
        dataBST.remove(numbers);
    }
    
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    inFile.close();
    
    
   
    ifstream inFile2(fileName.c_str());
    AVL_Tree dataAVL;
    while(inFile2 >> numbers)
    {
        dataAVL.insert(numbers);
    }
    inFile2.clear();
    inFile2.ignore(1);
    dataAVL.print();
    while(inFile2 >> numbers)
    {
        dataAVL.search(numbers);
    }
    
    inFile2.clear();
    inFile2.ignore(1);
    while(inFile2 >> numbers)
    {
        dataAVL.remove(numbers);
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    
    inFile2.close();
    
    
    ifstream inFile3(fileName.c_str());
    SPLAY_Tree dataSPLAY;
    while(inFile3 >> numbers)
    {
        dataSPLAY.insert(numbers);
    }
    inFile3.clear();
    inFile3.ignore(1);
    dataSPLAY.print();
    
    while(inFile3 >> numbers)
    {
        dataSPLAY.search(numbers);
    }
    
    inFile3.clear();
    inFile3.ignore(1);
    while(inFile3 >> numbers)
    {
        dataSPLAY.Delete(numbers);
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    
    inFile3.close();
    
    
    return 0;
}
