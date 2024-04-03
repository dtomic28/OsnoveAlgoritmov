//
// Created by danijel on 3/1/2024.
//

#include <iostream>
#include "Quicksort.h"
#include <ctime>
#include <vector>
#include <random>

using namespace std;

random_device rd;
mt19937 rng(rd());
std::uniform_int_distribution<int> uni(-500000, 500000);

void printArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void generateRandomSequence(vector<int>& arr, unsigned int numOfElements)
{
    arr.clear();
    for (int i = 0; i < numOfElements; i++)
    {
        arr.push_back(uni(rng));
    }
}

void generateRisingSequence(vector<int>& arr, unsigned int numOfElements)
{
    arr.clear();
    for (int i = 0; i < numOfElements; i++)
    {
        arr.push_back(i);
    }
}

void generateFallingSequence(vector<int>& arr, unsigned int numOfElements)
{
    arr.clear();
    for (int i = numOfElements; i > 0; i--)
    {
        arr.push_back(i);
    }
}

void printMenu()
{
    cout << "Hitro uredi - izbira" << endl;
    cout << endl;
    cout << "1 Generiraj nakljucno zaporedje" << endl;
    cout << "2 Generiraj urejeno narascujoce zaporedje" << endl;
    cout << "3 Generiraj urejeno padajoce zaporedje" << endl;
    cout << "4 Izpis zaporedja" << endl;
    cout << "5 Uredi" << endl;
    cout << "6 Konec" << endl;
    cout << endl;
    cout << "Vasa izbira: " << endl;
}

int main()
{
    clock_t start, finish;
    double duration;
    int izbira, numOfElements;
    bool running = true;
    vector<int> arr = {0};
    int* arrPtr = &arr[0];

    do
    {
        printMenu();

        cin >> izbira;

        switch (izbira)
        {
            case 6:
            {
                running = false;
                break;
            }
            case 1:
            {
                cout << "Vnesite st elementov: ";
                cin >> numOfElements;

                generateRandomSequence(arr, numOfElements);
                break;
            }
            case 2:
            {
                cout << "Vnesite st elementov: ";
                cin >> numOfElements;

                generateRisingSequence(arr, numOfElements);
                break;
            }
            case 3:
            {
                cout << "Vnesite st elementov: ";
                cin >> numOfElements;

                generateFallingSequence(arr, numOfElements);
                break;
            }
            case 4:
            {
                printArray(&arr[0], arr.size());
                break;
            }
            case 5:
            {
                if (!arr.empty())
                {
                    start = clock();
                    quickSort(&arr[0], 0, arr.size());
                    finish = clock();
                    duration = (double) (finish - start) / CLOCKS_PER_SEC;
                    cout << "Cas izvajanja: " << duration << "s" << endl;
                    cout << "Ali je pravilen sort?: " << (checkIfSorted(&arr[0], 0, arr.size()) ? "Pravilen" : "Nepravilen") << endl;
                }
                else
                {
                    cout << "Prazen array. Generirajte stevila!" << endl;
                }
                break;
            }
            default:
            {
                cout << "Naredili ste napako, poskusite ponovno" << endl;
                break;
            }
        }
    } while (running);

    return 0;
}
