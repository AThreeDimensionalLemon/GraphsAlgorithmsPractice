// 
// Name: main.cpp
// Author: Eisig Liang
// Last update: 27 October 2024
// Purpose: Implement and test Prim's and Djikstra's Algorithms
//

#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <limits>
#include "AdjacencyList.h"
using namespace std;

map<char, vector<char>> primsAlgorithm(map<char, vector<tuple<char, int, bool>>>adjacencyList) {
    vector<char> visitedVertices;
    map<char, vector<char>> mst;
    visitedVertices.push_back('A'); //First vertex

    while (true) { //Iterate until all vertices are visited
        int leastWeight = numeric_limits<int>::max();
        tuple<char, int, bool> leastWeightVertex;

        for (char visitingVertex : visitedVertices) { //Find least weighted edge within tree

            for (tuple<char, int, bool> vertex : adjacencyList[visitingVertex]) { //Find least weighted edge within vertex

                if (get<2>(vertex) == false and //Ignore visited vertices
                    get<1>(vertex) < leastWeight) //Weight is less than previously checked weights
                {
                    leastWeight = get<1>(vertex);
                    leastWeightVertex = vertex;
                }
            }
        }

        get<2>(leastWeightVertex) = true; //Mark leastWeightVertex as visited

        if (visitedVertices.size() == adjacencyList.size()) return mst;
    }
}

//void djikstrasAlgorithm(map<pair<char, int>, vector<tuple<pair<char, int>, int, bool>>>adjacencyList) {
//
//}

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

    // Test algorithm
    //map<char, vector<char>> mst(primsAlgorithm(primsList.getList()));

    // Test djikstrasAlgorithm()

    // Set up adjacency list
    char vertexNames[8] = { 'S', 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
    vector<pair<char, int>> vertices;
    for (char name : vertexNames) vertices.push_back(make_pair(name, numeric_limits<int>::max()));

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

    // Test algorithm
    //djikstrasAlgorithm(djikstrasList.getList());
}