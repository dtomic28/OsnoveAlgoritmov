//
// Created by Danijel Tomić on 11. 03. 24.
//
#include <iostream>
#include "dfs.h"
#include <array>
#include <fstream>

using namespace std;

void create2dArr(int** &arr,int size){
    arr = new int*[size];
    for(int i = 0; i < size; ++i)
        arr[i] = new int[size];
}

void delete2dArr(int** &arr, int size){
    for(int i = 0; i<size; i++)
        delete[] arr[i];
    delete[] arr;
}

int main(){
    int **arr, size, nodeSize;
    ifstream f("../DepthFirstSearch/graf.txt");

    if(!f.is_open()){
        cout << "File is missing";
        return 1;
    }

    f >> size;
    f >> nodeSize;

    create2dArr(arr, size);

    cout << size << endl;

    delete2dArr(arr, 50);

    return 0;
}