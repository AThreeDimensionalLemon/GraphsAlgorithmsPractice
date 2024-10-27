// 
// Name: main.cpp
// Author: Eisig Liang
// Last update: 27 October 2024
// Purpose: Implement and test Prim's and Djikstra's Algorithms
//

#include <iostream>
#include <list>
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
    AdjacencyList<char> djikstrasList(vector<char> {'S', 'A', 'B', 'C', 'D', 'E', 'F', 'G'});
    djikstrasList.addEdge('S', 'A', 5);
    djikstrasList.addEdge('S', 'B', 4);
    djikstrasList.addEdge('A', 'B', 1);
    djikstrasList.addEdge('A', 'D', 3);
    djikstrasList.addEdge('B', 'C', 4);
    djikstrasList.addEdge('B', 'E', 5);
    djikstrasList.addEdge('C', 'E', 14);
    djikstrasList.addEdge('C', 'F', 3);
    djikstrasList.addEdge('C', 'G', 8);
    djikstrasList.addEdge('D', 'E', 2);
    djikstrasList.addEdge('D', 'F', 7);
    djikstrasList.addEdge('D', 'G', 12);
    djikstrasList.addEdge('E', 'F', 10);
    djikstrasList.addEdge('F', 'G', 4);
}