//
// Created by Danijel Tomić on 11. 04. 24.
//
#include "Dijkstrov.h"
#include <iostream>
#include <fstream>

using namespace std;

void printMenu()
{
    cout << "Dijkstrov algoritem - izbira" << endl;
    cout << endl;
    cout << "1 Preberi graf iz datoteke" << endl;
    cout << "2 Zagon algoritma" << endl;
    cout << "3 Izpis najkrajse poti" << endl;
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
                ifstream inputFile("../Dijkstrov/graf.txt");
                inputFile >> size;
                inputFile >> connectionSize;
                Dijkstrov::initiateFromFile(size, inputFile);
                break;
            }
            case 2:
            {
                cout << "Vnesite start index: ";
                cin >> startIndex;

                Dijkstrov::run(Dijkstrov::nodes[startIndex]);
                break;
            }
            case 3:
            {
                cout << "Vnesite end index: ";
                cin >> endIndex;

                if (startIndex != -1)
                {
                    Dijkstrov::printPath(Dijkstrov::nodes[startIndex], Dijkstrov::nodes[endIndex]);
                    cout << endl;
                }
                break;
            }
            case 4:
            {
                running = false;
            }
        }
    } while (running);
    Dijkstrov::freeMatrix();
    return 0;
}