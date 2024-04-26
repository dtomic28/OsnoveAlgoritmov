//
// Created by Danijel Tomić on 24. 04. 24.
//
#include "FloydWarshallow.h"
#include <sstream>
#include <limits>
#include <iostream>

using namespace std;

#define NIL 1000000  // numerical_limits<int> je pri seštevku povzročilo overflow

std::vector<std::vector<int>> FloydWarshallow::d;
std::vector<std::vector<int>> FloydWarshallow::pi;
std::vector<std::vector<int>> FloydWarshallow::c;
size_t FloydWarshallow::size;

void FloydWarshallow::initiateFromFile(unsigned int inputSize, std::ifstream& inputFile)
{
    size = inputSize;
    std::string line;
    int intMax = std::numeric_limits<int>::max();
    c.clear();
    d.clear();
    pi.clear();

    c.resize(size, std::vector<int>(size, NIL));
    d.resize(size, std::vector<int>(size, NIL));
    pi.resize(size, std::vector<int>(size, -1));
    for (int i = 0; i < size; i++)
    {
        c[i][i] = 0;
    }
    while (std::getline(inputFile, line))
    {  // read line by line
        std::istringstream iss(line);
        int p, q, price;
        if ((iss >> p >> q >> price))
        {  // Read values from the line
            c[p - 1][q - 1] = price;
        }
    }
    d = c;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i != j && d[i][j] != NIL)
            {
                pi[i][j] = i;
            }
        }
    }
}

void FloydWarshallow::run()
{
    for (int k = 0; k < size; k++)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (d[i][j] > (d[i][k] + d[k][j]))
                {
                    d[i][j] = (d[i][k] + d[k][j]);
                    pi[i][j] = pi[k][j];
                }
            }
        }
    }
}
void FloydWarshallow::printPath(int s, int g)
{
    if (s == g)
    {
        std::cout << s << " ";
    }
    else if (pi[s][g] == -1)
    {
        std::cout << "Med " << s << " in " << g << " ni poti.";
    }
    else
    {
        printPath(s, pi[s][g]);
        std::cout << g << " ";
    }
}

void FloydWarshallow::printMatrix(std::vector<std::vector<int>> matrix)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            std::cout << matrix[i][j] << "\t";  // Print each value followed by a tab
        }
        std::cout << std::endl;  // Move to the next line after printing a row
    }
}
