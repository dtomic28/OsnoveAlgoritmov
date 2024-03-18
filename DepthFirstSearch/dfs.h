//
// Created by Danijel Tomić on 11. 03. 24.
//

#ifndef OSNOVEALGORITMOV_DFS_H
#define OSNOVEALGORITMOV_DFS_H

#include <string>
#include <fstream>
#include <utility>
#include <vector>
#include <stack>
#include <vector>

struct Node {
    Node(int previous, int length, int status, int index, std::string ime)
            : previous(previous), length(length), status(status), index(index), name(std::move(ime)) {}

    int previous;
    int length;
    int status;
    int index;
    std::string name;

    std::string toString() const {
        return this->name + " - " + "Index: " + std::to_string(this->index) + ", Status: " +
               std::to_string(this->status) + ", Previous: " + std::to_string(this->previous) +
               ", length from node s: " + std::to_string(this->length);
    }
};

bool operator==(const Node &n1, const Node &n2);

void dfs(int **matrix, int size, std::vector<Node> &nodes, Node &start);

void printPath(std::vector<Node> &nodes, Node &start, Node &vozlisce);

void initiateMatrixAndNodes(std::ifstream &inputFile, int **matrix, int size, std::vector<Node> &nodes);

#endif //OSNOVEALGORITMOV_DFS_H
