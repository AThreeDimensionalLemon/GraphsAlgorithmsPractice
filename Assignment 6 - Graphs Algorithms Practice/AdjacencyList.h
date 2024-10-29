// 
// Name: main.cpp
// Author: Eisig Liang
// Last update: 28 October 2024
// Purpose: Create an adjacency list
// Notices:
//     1. No protection against repeat edges; be careful when using for direct user interactions
//     2. Can only form adjacency lists from vectors
//     3. Modified for Prims and Djikstra's Algorithms; use for other algorithms untested
// Potential improvements:
//     1. Make edge structs point to vertices instead of vertices pointing to other vertices (no, absolutely do not do that)
//     2. Use lists instead of vectors to allow for traversal
// 

#pragma once
#include <iostream>
#include <map>
#include <vector>
using namespace std;

template<typename T>
class AdjacencyList
{
public: //Won't be a security issue; only being used as a template
    struct edge {
        int weight;
        bool isVisited;
    };

protected:
    map<T, //Vertex
        map<T, //Connected vertex
        edge>> list;
    bool isDirected;

public:
    AdjacencyList(vector<T> vertices, bool isDirected = false);
    void addEdge(T source, T target, int weight = 1); 
    map<T, map<T, edge>> getList();
};

template<typename T>
AdjacencyList<T>::AdjacencyList(vector<T> vertices, bool inIsDirected) {

    for (T vertex : vertices) {
        map<T, edge> edgesMap;
        list.insert({ vertex, edgesMap });
    }

    isDirected = inIsDirected;
}

template<typename T>
void AdjacencyList<T>::addEdge(T source, T target, int weight) {
    edge sourceTargetEdge{ weight, false };
    list[source][target] = sourceTargetEdge;

    if (not isDirected) {
        edge targetSourceEdge{ weight, false };
        list[target][source] = targetSourceEdge;
    }
}

template<typename T>
map<T, map<T, typename AdjacencyList<T>::edge>> AdjacencyList<T>::getList() {
    return list;
}