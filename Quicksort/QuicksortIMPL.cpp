//
// Created by danijel on 3/1/2024.
//

#include <iostream>
#include "Quicksort.h"
#include <ctime>

using namespace std;

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void printMenu(){
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


int main(){
    clock_t start, finish;
    double duration;
    int izbira;
    bool running = true;


    do{
        printMenu();

        cin >> izbira;

        switch (izbira) {
            case 0:{
                cout << 0;
                running = false;
                break;
            }
            case 1:{
                cout << 1;
                break;
            }
            case 2:{
                cout << 2;
                break;
            }
            case 3:{
                cout << 3;
                break;
            }
            case 4:{
                cout << 4;
                break;
            }
            case 5:{
                cout << 5;
                break;
            }
            case 6:{
                cout << 6;
                break;
            }
            default:{
                cout << "Naredili ste napako, poskusite ponovno";
                break;
            }

        }
    }while(running);



    //quickSort(arr, 0, size-1);
    //cout << (checkIfSorted(arr, 0, size-1) ? "True" : "False");

    return 0;
}


