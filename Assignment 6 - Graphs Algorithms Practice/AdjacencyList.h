// 
// Name: main.cpp
// Author: Eisig Liang
// Last update: 27 October 2024
// Purpose: Create an adjacency list
// Notices:
//     1. No protection against repeat edges; be careful when using for direct user interactions
//     2. Can only form adjacency lists from vectors
//     3. Modified for Prims and Djikstra's Algorithms; use for other algorithms untested
// 

#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

template<typename T>
class AdjacencyList
{
protected:
    struct edge {
        T connectedVertex; //Not a key because too much refactoring before deadline
        int weight;
        bool isVisited;
    };

private:
    map<T, vector<edge>> list;
    bool isDirected;

public:
    AdjacencyList(vector<T> vertices, bool isDirected = false);
    void addEdge(T source, T target, int weight = 1); 
    map<T, vector<edge>> getList();
};

template<typename T>
AdjacencyList<T>::AdjacencyList(vector<T> vertices, bool inIsDirected) {

    for (T vertex : vertices) {
        vector<edge> vertexVector;
        list.insert({ vertex, vertexVector });
    }

    isDirected = inIsDirected;
}

template<typename T>
void AdjacencyList<T>::addEdge(T source, T target, int weight) {
    edge sourceTargetEdge{ target, weight, false };
    list[source].push_back(sourceTargetEdge);

    if (not isDirected) {
        edge targetSourceEdge{ source, weight, false };
        list[target].push_back(targetSourceEdge);
    }
}

template<typename T>
map<T, vector<typename AdjacencyList<T>::edge>> AdjacencyList<T>::getList() {
    return list;
}