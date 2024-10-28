// 
// Name: main.cpp
// Author: Eisig Liang
// Last update: 27 October 2024
// Purpose: Create an adjacency list
// Notices:
//     1. No protection against repeat edges; be careful when using for direct user interactions
//     2. Can only form adjacency lists from vectors
//     3. Modified for Prims and Djikstra's Algorithms; use for other algorithms unstable
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
private:
    map<T, //Vertex is map key
        vector< //List of vertex's edges is map value
        tuple<T, //Edge is first tuple value
        int, //Weight is second tuple value
        bool //Visit status is third tuple value
        >>> list;
    bool isDirected;

public:
    AdjacencyList(vector<T> vertices, bool isDirected = false);
    void addEdge(T source, T target, int weight = 1); 
    map<T, vector<tuple<T, int, bool>>> getList();
};

template<typename T>
AdjacencyList<T>::AdjacencyList(vector<T> vertices, bool inIsDirected) {

    for (T vertex : vertices) {
        vector<tuple<T, int, bool>> vertexVector;
        list.insert({ vertex, vertexVector });
    }

    isDirected = inIsDirected;
}

template<typename T>
void AdjacencyList<T>::addEdge(T source, T target, int weight) {
    list[source].push_back(make_tuple(target, weight, false));
    if (not isDirected) list[target].push_back(make_tuple(source, weight, false));
}

template<typename T>
map<T, vector<tuple<T, int, bool>>> AdjacencyList<T>::getList() {
    return list;
}