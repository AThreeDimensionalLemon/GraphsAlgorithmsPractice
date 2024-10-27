// 
// Name: main.cpp
// Author: Eisig Liang
// Last update: 27 October 2024
// Purpose: Create an adjacency list
// Notices:
//     1. No protection against repeat edges; be careful when using for direct user interactions
//     2. Can only form adjacency lists from vectors
// 

#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <utility>
using namespace std;

template<typename T>
class AdjacencyList
{
private:
    map<T, //Vertex is map key
        vector< //List of vertex's edges is map value
        pair<T, //Edge is first pair value
        int //Weight is second pair value
        >>> list;
    bool isDirected;

public:
    AdjacencyList(vector<T> vertices, bool isDirected = false);
    void addEdge(T source, T target, int weight = 1); 
    map<T, vector<pair<T, int>>> getList();
};

template<typename T>
AdjacencyList<T>::AdjacencyList(vector<T> vertices, bool inIsDirected) {

    for (T vertex : vertices) {
        vector<pair<T, int>> vertexVector;
        list.insert({ vertex, vertexVector });
    }

    isDirected = inIsDirected;
}

template<typename T>
void AdjacencyList<T>::addEdge(T source, T target, int weight) {
    list[source].push_back(make_pair(target, weight));
    if (not isDirected) list[target].push_back(make_pair(source, weight));
}

template<typename T>
map<T, vector<pair<T, int>>> AdjacencyList<T>::getList() {
    return list;
}