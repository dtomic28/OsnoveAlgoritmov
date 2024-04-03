//
// Created by Danijel Tomić on 1. 03. 24.
//

#include "Quicksort.h"
#include <iostream>
#include <cmath>

int divide(int* arr, int bottomIndex, int topIndex)
{
    int left = bottomIndex;
    int right = topIndex;
    int median = (bottomIndex + topIndex) / 2;
    std::swap(arr[bottomIndex], arr[median]);

    int pivot = arr[bottomIndex];

    while (left < right)
    {
        while (arr[left] <= pivot && left < topIndex)
            left++;

        while (arr[right] > pivot && right > bottomIndex)
            right--;

        if (left < right)
            std::swap(arr[left], arr[right]);
    }
    std::swap(arr[bottomIndex], arr[right]);
    return right;
}

void quickSort(int* arr, int bottomIndex, int topIndex)
{
    int pivotIndex;
    if (bottomIndex < topIndex)
    {
        pivotIndex = divide(arr, bottomIndex, topIndex);
        quickSort(arr, bottomIndex, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, topIndex);
    }
}

bool checkIfSorted(int* arr, int bottomIndex, int topIndex)
{
    for (int i = bottomIndex; i < topIndex; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            std::cout << "Error at index: " << i << std::endl;
            return false;
        }
    }
    return true;
}
