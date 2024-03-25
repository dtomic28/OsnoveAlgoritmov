//
// Created by Danijel Tomić on 25. 03. 24.
//

#include "Kruskal.h"
#include <limits>
#include <iostream>
#include <sstream>
#include <string>
#include <random>
#include <iostream>

unsigned int Kruskal::matrixSize = 0;
unsigned int** Kruskal::matrix = nullptr;
unsigned int* Kruskal::nodeSet = nullptr;
std::vector<Connection> Kruskal::connections;
std::vector<Connection> Kruskal::result;
bool Kruskal::isInitiated = false;

void Kruskal::initiateFromFile(unsigned int size, std::ifstream &inputFile) {
    isInitiated = true;
    std::string line;
    matrixSize = size;
    matrix = new unsigned int *[size];
    nodeSet = new unsigned int[size];
    for (int i = 0; i < size; i++) {
        nodeSet[i] = 0;
        matrix[i] = new unsigned int[size]{0};
    }
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            matrix[i][j] = std::numeric_limits<unsigned int>::max();
        }
    }
    while (std::getline(inputFile, line)) { // Read line by line
        std::istringstream iss(line);
        int p, q, price;
        if ((iss >> p >> q >> price)) { // Read values from the line
            matrix[p - 1][q - 1] = price;
            connections.emplace_back(p-1,q-1,price);
        }
    }

}

void Kruskal::printMatrix() {
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            std::cout << matrix[i][j] << "\t"; // Print each value followed by a tab
        }
        std::cout << std::endl; // Move to the next line after printing a row
    }
}

void Kruskal::freeMatrix() {
    if(!isInitiated)
        return;
    for(int i = 0; i<matrixSize; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] nodeSet;
}

void Kruskal::run() {
    std::sort(connections.begin(), connections.end());
    result.clear();
    bool finished = false;
    int i = 0;

    while(!finished){
        if(nodeSet[connections[i].p] != nodeSet[connections[i].q] || nodeSet[connections[i].p] == 0 && nodeSet[connections[i].q] == 0){ //If not case 1
            if(nodeSet[connections[i].p] != 0 && nodeSet[connections[i].q] != 0){
                result.push_back(connections[i]);
                joinSet(nodeSet[connections[i].p], nodeSet[connections[i].q]);
            }else if(nodeSet[connections[i].p] != 0 && nodeSet[connections[i].q] == 0){
                result.push_back(connections[i]);
                nodeSet[connections[i].q] = nodeSet[connections[i].p];
            }else if (nodeSet[connections[i].p] == 0 && nodeSet[connections[i].q] == 0) {
                result.push_back(connections[i]);
                unsigned int newSet = createNewSet();
                nodeSet[connections[i].p] = newSet;
                nodeSet[connections[i].q] = newSet;
            }
        }
        if(result.size() == matrixSize - 1)
            finished = true;
        else
            i++;
    }
    std::cout << "Izhodiscno stevilo povezav: " << connections.size() << ", stevilo vozlisc: " << matrixSize << std::endl;
    std::cout << "Stevilo sprejetih povezav: " << result.size() << std::endl;
}

void Kruskal::joinSet(unsigned int set1, unsigned int set2) {
    for(int i = 0; i<matrixSize; i++){
        if(nodeSet[i] == set2)
            nodeSet[i] = set1;
    }
}

unsigned int Kruskal::createNewSet() {
    unsigned int* maxElement = std::max_element(nodeSet, nodeSet + matrixSize);

    (*maxElement)++;

    return *maxElement;
}

void Kruskal::initiateFromSize(unsigned int size) {
    isInitiated = true;
    matrixSize = size;
    matrix = new unsigned int *[size];
    nodeSet = new unsigned int[size];
    for (int i = 0; i < size; i++) {
        nodeSet[i] = 0;
        matrix[i] = new unsigned int[size]{0};
    }
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            matrix[i][j] = std::numeric_limits<unsigned int>::max();
        }
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100); // Adjust range as needed
    connections.clear();
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            int price = dis(gen);
            matrix[i][j] = price;
            connections.emplace_back(i, j, price);
        }
    }

}

unsigned int Kruskal::sumOfPrice() {
   unsigned sum = 0;
   for(auto &node : result){
       sum += node.price;
   }
   return sum;
}

void Kruskal::printResult() {
    for(auto connection : result){
        std::cout << connection.toString() << std::endl;
    }
    std::cout << "Skupna cena minimalnega vpetega drevesa: " << sumOfPrice() << std::endl;
}
