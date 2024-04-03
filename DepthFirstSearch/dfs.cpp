//
// Created by Danijel Tomić on 11. 03. 24.
//

#include "dfs.h"
#include <sstream>
#include <iostream>

void initiateMatrixAndNodes(std::ifstream& inputFile, int** matrix, int size, std::vector<Node>& nodes)
{
    std::string line;
    unsigned int c = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = 0;
        }
    }

    while (std::getline(inputFile, line))
    {  // Read line by line
        std::istringstream iss(line);
        int from, to, length;
        if ((iss >> from >> to >> length))
        {  // Read values from the line
            matrix[from - 1][to - 1] = 1;
            matrix[to - 1][from - 1] = 1;
        }
    }
}

void dfs(int** matrix, int size, std::vector<Node>& nodes, Node& start)
{
    std::stack<Node> nodeStack;
    for (auto& node : nodes)
    {
        node.status = 0;
        node.previous = -1;
    }

    start.status = 1;
    start.length = 0;
    start.previous = -1;
    nodeStack.push(start);

    while (!nodeStack.empty())
    {
        auto node = nodeStack.top();
        nodeStack.pop();

        for (int i = 0; i < size; i++)
        {
            if (matrix[node.index][i] == 1 && nodes[i].status == 0)
            {
                nodes[i].status = 1;
                nodes[i].length = node.length + 1;
                nodes[i].previous = node.index;
                nodeStack.push(nodes[i]);
            }
        }

        nodes[node.index].status = 2;
    }
}

bool operator==(const Node& n1, const Node& n2)
{
    return n1.previous == n2.previous && n1.length == n2.length && n1.status == n2.status && n1.index == n2.index && n1.name == n2.name;
}

void printPath(std::vector<Node>& nodes, Node& start, Node& vozlisce)
{
    if (start == vozlisce)
    {
        std::cout << "Pot je: " << vozlisce.index << " ";
    }
    else
    {
        if (vozlisce.previous == -1)
        {
            std::cout << "Med " << start.index << " in " << vozlisce.index << " ni poti!" << std::endl;
        }
        else
        {
            printPath(nodes, start, nodes[vozlisce.previous]);
            std::cout << vozlisce.index << " ";
        }
    }
}