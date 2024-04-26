//
// Created by Danijel Tomić on 26. 04. 24.
//
#include "FloydWarshallow.h"
#include <iostream>
#include <fstream>

using namespace std;

void printMenu()
{
    cout << "Floyd-Warshallow - izbira" << endl;
    cout << endl;
    cout << "1 Preberi graf iz datoteke" << endl;
    cout << "2 Zagon algoritma" << endl;
    cout << "3 Izpis najkrajse poti med vozliscema s in g" << endl;
    cout << "4 Konec" << endl;
    cout << endl;
    cout << "Vasa izbira: ";
}

int main()
{
    int size, connectionSize, izbira, startIndex = -1, endIndex = -1;
    bool running = true;

    do
    {
        printMenu();

        cin >> izbira;

        switch (izbira)
        {
            case 1:
            {
                ifstream inputFile("../FloydWarshallow/graf2.txt");
                inputFile >> size;
                inputFile >> connectionSize;
                FloydWarshallow::initiateFromFile(size, inputFile);
                break;
            }
            case 2:
            {
                FloydWarshallow::run();
                break;
            }
            case 3:
            {
                cout << "Vnesite start index: ";
                cin >> startIndex;

                cout << "Vnesite end index: ";
                cin >> endIndex;

                FloydWarshallow::printPath(startIndex, endIndex);
                cout << "Dolzina poti: " << FloydWarshallow::d[startIndex][endIndex] << endl;
                break;
            }
            case 4:
            {
                running = false;
            }
        }
    } while (running);
    return 0;
}