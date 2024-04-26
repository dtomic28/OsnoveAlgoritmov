//
// Created by Danijel Tomić on 24. 04. 24.
//

#ifndef OSNOVEALGORITMOV_FLOYDWARSHALLOW_H
#define OSNOVEALGORITMOV_FLOYDWARSHALLOW_H
#include <vector>
#include <fstream>
#include <string>

class FloydWarshallow
{
private:
    static std::vector<std::vector<int>> pi;
    static size_t size;

public:
    static std::vector<std::vector<int>> d;
    static std::vector<std::vector<int>> c;
    static void initiateFromFile(unsigned int size, std::ifstream& inputFile);
    static void printMatrix(std::vector<std::vector<int>> matrix);
    static void run();
    static void printPath(int s, int g);
};

#endif  // OSNOVEALGORITMOV_FLOYDWARSHALLOW_H
