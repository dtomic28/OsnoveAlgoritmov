//
// Created by Danijel Tomić on 25. 03. 24.
//

#ifndef OSNOVEALGORITMOV_KRUSKAL_H
#define OSNOVEALGORITMOV_KRUSKAL_H

#include <fstream>
#include <vector>

struct Connection {
    Connection(int p, int q, int price) : p(p), q(q), price(price) {};

    int p, q, price;

    std::string toString() const {
        return "(" + std::to_string(p) + ", " + std::to_string(q) + ", " + std::to_string(price) + ")";
    }

    bool operator<(const Connection &other) const {
        return price < other.price;
    }
};

class Kruskal {
private:
    static unsigned int matrixSize;
    static unsigned int *nodeSet;

    static void joinSet(unsigned int set1, unsigned int set2);

    static unsigned int createNewSet();

    static bool isInitiated;

    static unsigned int sumOfPrice();

public:
    static unsigned int **matrix;
    static std::vector<Connection> connections;
    static std::vector<Connection> result;

    static void initiateFromFile(unsigned int size, std::ifstream &inputFile);

    static void initiateFromSize(unsigned int size);

    static void printMatrix();

    static void freeMatrix();

    static void run();

    static void printResult();
};


#endif //OSNOVEALGORITMOV_KRUSKAL_H
