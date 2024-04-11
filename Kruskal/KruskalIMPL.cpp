//
// Created by Danijel Tomić on 25. 03. 24.
//
#include <iostream>
#include "Kruskal.h"

using namespace std;

void printMenu()
{
    cout << "Kruskalov algoritem - izbira" << endl;
    cout << endl;
    cout << "1 Preberi graf iz datoteke" << endl;
    cout << "2 Generiraj naključni graf" << endl;
    cout << "3 Poženi" << endl;
    cout << "4 Izpis sprejetih povezav" << endl;
    cout << "5 Konec" << endl;
    cout << endl;
    cout << "Vasa izbira: ";
}

int main()
{
    int size, connectionSize, izbira;
    bool running = true;

    do
    {
        printMenu();

        cin >> izbira;

        switch (izbira)
        {
            case 1:
            {
                ifstream inputFile("../Kruskal/graf1.txt");
                inputFile >> size;
                inputFile >> connectionSize;

                Kruskal::freeMatrix();

                Kruskal::initiateFromFile(size, inputFile);
                inputFile.close();
                break;
            }
            case 2:
            {
                cout << "Vnesite št. povezav";
                cin >> size;

                if (size > 1500)
                {
                    cout << "Vnesite manj kot 5000 povezav" << endl;
                    break;
                }

                Kruskal::freeMatrix();
                Kruskal::initiateFromSize(size);
                break;
            }
            case 3:
            {
                Kruskal::run();
                break;
            }
            case 4:
            {
                Kruskal::printResult();
                break;
            }
            case 5:
            {
                running = false;
                break;
            }
            default:
            {
                cout << "Napacna izbira, poskusite ponovno" << endl;
                break;
            }
        }
    } while (running);

    return 0;
}