//
// Created by Danijel Tomić on 11. 04. 24.
//

#ifndef OSNOVEALGORITMOV_DIJKSTROV_H
#define OSNOVEALGORITMOV_DIJKSTROV_H
#include <vector>
#include <string>
#include <fstream>
struct Node
{
    Node(int previous, int price, int status, int index, std::string ime)
        : previous(previous)
        , price(price)
        , index(index)
        , name(std::move(ime))
    {
    }

    Node(const Node& node) = default;

    Node()
        : price(0)
        , index(-1)
        , previous(-1)
    {
    }

    int previous;
    int price;
    int index;
    std::string name;

    std::string toString() const
    {
        return this->name + " - " + "Index: " + std::to_string(this->index) +
               ", Status: " + ", Previous: " + std::to_string(this->previous) + ", length from node s: " + std::to_string(this->price);
    }

    bool operator<(const Node& other) const
    {
        return price < other.price;
    }
};

class Dijkstrov
{
private:
    static unsigned int matrixSize;
    static bool isInitiated;

public:
    static unsigned int** matrix;
    static std::vector<Node> nodes;

    static void initiateFromFile(unsigned int size, std::ifstream& inputFile);
    static void freeMatrix();
    static void printMatrix();
    static void run(Node& start);
    static std::vector<int> getNeigbours(int index);
    static void printPath(Node& start, Node& vozlisce);
};

#endif  // OSNOVEALGORITMOV_DIJKSTROV_H
