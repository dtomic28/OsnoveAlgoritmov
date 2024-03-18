//
// Created by Danijel Tomić on 11. 03. 24.
//
#include <iostream>
#include "dfs.h"

using namespace std;

void createMatrix(int **&arr, int size) {
    arr = new int *[size];
    for (int i = 0; i < size; ++i)
        arr[i] = new int[size];
}

void deleteMatrix(int **&arr, int size) {
    for (int i = 0; i < size; i++)
        delete[] arr[i];
    delete[] arr;
}

void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << "\t"; // Print each value followed by a tab
        }
        std::cout << std::endl; // Move to the next line after printing a row
    }
}

void printMenu() {
    cout << "Iskanje v globino - izbira" << endl;
    cout << endl;
    cout << "1 Preberi graf iz datoteke" << endl;
    cout << "2 Pozeni iskanje iz vozlisca s" << endl;
    cout << "3 Izpis seznama vozlisc in njihovih podatkov" << endl;
    cout << "4 Izpis poti med vozliscema s in d" << endl;
    cout << "5 Konec" << endl;
    cout << endl;
    cout << "Vasa izbira: ";
}

int main() {
    int **matrix, size, nodeSize, izbira, startIndex, endIndex;
    vector<Node> nodes;
    ifstream inputFile("../DepthFirstSearch/graf_big.txt");
    bool running = true;

    do {
        printMenu();

        cin >> izbira;

        switch (izbira) {
            case 1: {
                if (!inputFile.is_open()) {
                    cout << "File is missing";
                    return 1;
                }

                inputFile >> size;
                inputFile >> nodeSize;

                createMatrix(matrix, size);

                initiateMatrixAndNodes(inputFile, matrix, size, nodes);
                for (int i = 0; i < size; i++) {
                    nodes.emplace_back(-1, 1, 0, i, "Vozlisce " + to_string(i));
                }
                break;
            }
            case 3: {
                for (auto node: nodes) {
                    cout << node.toString() << endl;
                }
                break;
            }
            case 2: {
                cout << "Input index of s: ";
                cin >> startIndex;
                dfs(matrix, size, nodes, nodes[startIndex]);
                break;
            }
            case 4: {
                cout << "Input index of d: ";
                cin >> endIndex;
                printPath(nodes, nodes[startIndex], nodes[endIndex]);
                cout << endl;
                break;
            }
            case 5: {
                running = false;
                break;
            }
            default: {
                cout << "Napacna izbira, poskusite ponovno" << endl;
                break;
            }
        }
    } while (running);

    deleteMatrix(matrix, size);

    return 0;
}