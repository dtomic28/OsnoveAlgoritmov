//
// Created by Danijel Tomić on 11. 03. 24.
//

#ifndef OSNOVEALGORITMOV_DFS_H
#define OSNOVEALGORITMOV_DFS_H
#include <string>

struct Node{
    int previous;
    int length;
    int status;
    int index;
    std::string ime;
};

void dfs();
void printPath();

#endif //OSNOVEALGORITMOV_DFS_H
