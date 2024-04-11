//
// Created by Danijel Tomić on 11. 04. 24.
//
#include "Dijkstrov.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int size, connectionSize;
    ifstream inputFile("../Dijkstrov/graf.txt");
    inputFile >> size;
    inputFile >> connectionSize;
    cout << size << endl;
    cout << connectionSize << endl;
    Dijkstrov::initiateFromFile(size, inputFile);
    Dijkstrov::printMatrix();
    Dijkstrov::freeMatrix();
}