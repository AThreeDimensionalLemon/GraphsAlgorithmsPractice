// 
// Name: main.cpp
// Author: Eisig Liang
// Last update: 27 October 2024
// Purpose: Create an adjacency list
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
    map<T, vector<pair<T, int>>> list;

public:
    AdjacencyList(vector<T> vertices);
    void addEdge(T source, T target, int weight = 1); 
    map<T, vector<pair<T, int>>> getList();
};

template<typename T>
AdjacencyList<T>::AdjacencyList(vector<T> vertices) {

    for (T vertex : vertices) {
        vector<pair<T, int>> vertexVector;
        list.insert({ vertex, vertexVector });
    }
}

template<typename T>
void AdjacencyList<T>::addEdge(T source, T target, int weight) {
    list[source].push_back(make_pair(target, weight));
}

template<typename T>
map<T, vector<pair<T, int>>> AdjacencyList<T>::getList() {
    return list;
}