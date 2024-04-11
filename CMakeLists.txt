cmake_minimum_required(VERSION 3.26)
project(OsnoveAlgoritmov)

set(CMAKE_CXX_STANDARD 17)

add_executable(Quicksort Quicksort/Quicksort.cpp
        Quicksort/QuicksortIMPL.cpp
        Quicksort/Quicksort.h)
add_executable(DepthFirstSearch DepthFirstSearch/dfs.cpp DepthFirstSearch/dfs.h
        DepthFirstSearch/dfsIMPL.cpp
        Dijkstrov/Dijkstrov.cpp
        Dijkstrov/Dijkstrov.h
        Dijkstrov/DijkstrovIMPL.cpp)
add_executable(Kruskal Kruskal/KruskalIMPL.cpp
        Kruskal/Kruskal.cpp
        Kruskal/Kruskal.h)
add_executable(Dijkstrov Dijkstrov/Dijkstrov.cpp Dijkstrov/Dijkstrov.h Dijkstrov/DijkstrovIMPL.cpp)
