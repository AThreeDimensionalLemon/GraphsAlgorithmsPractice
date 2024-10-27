// 
// Name: main.cpp
// Author: Eisig Liang
// Last update: 27 October 2024
// Purpose: Implement and test Prim's and Djikstra's Algorithms
//

#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include "AdjacencyList.h"
using namespace std;

void primsAlgorithm() {

}

void djikstrasAlgorithm() {

}

int main() { // Test algorithms' implementations

    // Test primsAlgorithm()

    // Set up adjacency list
    AdjacencyList<char> primsList(vector<char> {'A', 'B', 'C', 'D', 'E', 'F'});
    primsList.addEdge('A', 'B', 2);
    primsList.addEdge('A', 'C', 5);
    primsList.addEdge('A', 'D', 2);
    primsList.addEdge('A', 'E', 3);
    primsList.addEdge('B', 'D', 0);
    primsList.addEdge('C', 'D', 1);
    primsList.addEdge('C', 'E', 8);
    primsList.addEdge('D', 'E', 4);
    primsList.addEdge('D', 'F', 8);

    // Test djikstrasAlgorithm()

    // Set up adjacency list
    char vertexNames[8] = { 'S', 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
    vector<pair<char, int>> vertices;
    for (char name : vertexNames) vertices.push_back(make_pair(name, numeric_limits<int>::max()));
    //map<char, int> distance;
    //for (char vertex : vertices) distance.insert({ vertex, numeric_limits<int>::max() });

    AdjacencyList<pair<char, int>> djikstrasList(vertices);
    djikstrasList.addEdge(vertices[0], vertices[1], 5);
    djikstrasList.addEdge(vertices[0], vertices[2], 4);
    djikstrasList.addEdge(vertices[1], vertices[2], 1);
    djikstrasList.addEdge(vertices[1], vertices[4], 3);
    djikstrasList.addEdge(vertices[2], vertices[3], 4);
    djikstrasList.addEdge(vertices[2], vertices[5], 5);
    djikstrasList.addEdge(vertices[3], vertices[5], 14);
    djikstrasList.addEdge(vertices[3], vertices[6], 3);
    djikstrasList.addEdge(vertices[3], vertices[7], 8);
    djikstrasList.addEdge(vertices[4], vertices[5], 2);
    djikstrasList.addEdge(vertices[4], vertices[6], 7);
    djikstrasList.addEdge(vertices[4], vertices[7], 12);
    djikstrasList.addEdge(vertices[5], vertices[6], 10);
    djikstrasList.addEdge(vertices[6], vertices[7], 4);
}