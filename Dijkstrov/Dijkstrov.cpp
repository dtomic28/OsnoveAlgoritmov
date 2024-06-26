//
// Created by Danijel Tomić on 11. 04. 24.
//

#include "Dijkstrov.h"
#include <limits>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

unsigned int Dijkstrov::matrixSize = 0;
unsigned int** Dijkstrov::matrix = nullptr;
std::vector<Node> Dijkstrov::nodes;
bool Dijkstrov::isInitiated = false;

void Dijkstrov::initiateFromFile(unsigned int size, std::ifstream& inputFile)
{
    isInitiated = true;
    string line;
    matrixSize = size;
    matrix = new unsigned int*[size];
    for (int i = 0; i < matrixSize; i++)
        matrix[i] = new unsigned int[size];

    for (int i = 0; i < size; i++)
    {
        nodes.emplace_back(Node{-1, numeric_limits<int>::max(), 0, i, "Node"});
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = std::numeric_limits<unsigned int>::max();
        }
    }

    while (std::getline(inputFile, line))
    {  // Read line by line
        std::istringstream iss(line);
        int p, q, price;
        if ((iss >> p >> q >> price))
        {  // Read values from the line
            matrix[p - 1][q - 1] = price;
            matrix[q - 1][p - 1] = price;
        }
    }
}

void Dijkstrov::freeMatrix()
{
    if (!isInitiated)
        return;
    for (int i = 0; i < matrixSize; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
void Dijkstrov::printMatrix()
{
    for (int i = 0; i < matrixSize; ++i)
    {
        for (int j = 0; j < matrixSize; ++j)
        {
            std::cout << matrix[i][j] << "\t";  // Print each value followed by a tab
        }
        std::cout << std::endl;  // Move to the next line after printing a row
    }
}
std::vector<int> Dijkstrov::getNeigbours(int index)
{
    std::vector<int> neigbours;
    for (int i = 0; i < matrixSize; i++)
    {
        if (matrix[index][i] < numeric_limits<int>::max() && matrix[index][i] != 0)
        {
            neigbours.push_back(i);
        }
    }
    return neigbours;
}
void Dijkstrov::run(Node& start)
{
    for (auto& v : nodes)
    {
        v.price = numeric_limits<int>::max();
        v.previous = -1;
    }
    start.price = 0;
    std::vector<Node> queue;
    queue.push_back(start);
    vector<int> neighbours;
    while (!queue.empty())
    {
        std::sort(queue.begin(), queue.end());
        Node u = queue[0];
        queue.erase(queue.begin());
        neighbours = getNeigbours(u.index);
        for (auto v : neighbours)
        {
            if (nodes[v].price > u.price + matrix[u.index][v])
            {
                nodes[v].price = u.price + matrix[u.index][v];
                nodes[v].previous = u.index;
                queue.push_back(nodes[v]);
            }
        }
    }
}

bool operator==(const Node& n1, const Node& n2)
{
    return n1.previous == n2.previous && n1.price == n2.price && n1.index == n2.index;
}

void Dijkstrov::printPath(Node& start, Node& vozlisce)
{
    if (start == vozlisce)
    {
        std::cout << "Pot je: " << vozlisce.index;
    }
    else
    {
        if (vozlisce.previous == -1)
        {
            std::cout << "Med " << start.index << " in " << vozlisce.index << " ni poti!" << std::endl;
        }
        else
        {
            printPath(start, nodes[vozlisce.previous]);
            std::cout << " -> " << vozlisce.index << " (dolzina = " << vozlisce.price << ")";
        }
    }
}
