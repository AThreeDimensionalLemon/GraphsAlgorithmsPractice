// 
// Name: main.cpp
// Author: Eisig Liang
// Last update: 28 October 2024
// Purpose: Implement and test Prim's and Djikstra's Algorithms
//

#include "AdjacencyList.h"
#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <utility>
using namespace std;

map<char, vector<char>> primsAlgorithm(map<char, map<char, typename AdjacencyList<char>::edge>>adjacencyList) {
    vector<char> visitedVertices;
    map<char, vector<char>> mst;
    vector<char> connectedVertices;

    //Add first vertex
    visitedVertices.push_back('A'); 
    mst.insert({ 'A', connectedVertices });
    for (auto vertex : adjacencyList['A']) { //I lost a bit of my soul when I found out I could've just used auto
        vertex.second.isVisited = true;
        adjacencyList[vertex.first]['A'].isVisited = true;
    }

    while (visitedVertices.size() < adjacencyList.size()) {
        int leastWeight = numeric_limits<int>::max();
        char lightestVertex, lastVertex;

        for (auto visitingVertex : visitedVertices) { //Iterate through tree

            for (auto connectedVertex : adjacencyList[visitingVertex]) { //Iterate through edges

                if (connectedVertex.second.isVisited == false and 
                    connectedVertex.second.weight < leastWeight)
                {
                    leastWeight = connectedVertex.second.weight;
                    lightestVertex = connectedVertex.first;
                    lastVertex = visitingVertex;
                }
            }
        }

        //Update isVisited variables
        for (auto connectedVertex : adjacencyList[lightestVertex]) //I don't wanna refactor ;(
            adjacencyList[connectedVertex.first][lightestVertex].isVisited = true;
        adjacencyList[lightestVertex][lastVertex].isVisited = true;

        //Update tree
        mst[lastVertex].push_back(lightestVertex);
        if (mst.find(lightestVertex) == mst.end()) mst.insert({ lightestVertex, connectedVertices });
        mst[lightestVertex].push_back(lastVertex);
        visitedVertices.push_back(lightestVertex);
    }

    return mst;
}

map<char, int> djikstrasAlgorithm(map<tuple<char, int, bool>, map<tuple<char, int, bool>, typename AdjacencyList<tuple<char, int, bool>>::edge>>adjacencyList, vector<tuple<char, int, bool>> inVertices) {
    map<char, int> distances; //Map to return
    vector<char> visitedVerticies;
    map<char, int> inVerticesIndexes = {
        {'S', 0},
        {'A', 1},
        {'B', 2},
        {'C', 3},
        {'D', 4},
        {'E', 5},
        {'F', 6},
        {'G', 7},
    };

    //Start on 'S' vertex
    visitedVerticies.push_back('S');
    distances.insert({ 'S', 0 });
    get<1>(inVertices[0]) = 0;
    get<2>(inVertices[0]) = true;

    while (visitedVerticies.size() < inVertices.size()) {

        for (auto visitingVertex : visitedVerticies) {

            for (auto edge : adjacencyList[inVertices[inVerticesIndexes[visitingVertex]]]) { //Won't fix: I don't have the experience to work with structs; readability will have to suffer

                get<1>(inVertices[inVerticesIndexes[get<0>(edge.first)]]);
            }
        }
    }

    return distances;
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

    // Test algorithm
    cout << "Testing primsAlgorithm():" << endl;
    map<char, vector<char>> primsMst(primsAlgorithm(primsList.getList()));
    cout << "Minimum spanning tree formed by Prim's Algorithm:" << endl;
    cout << "Source:    Target:" << endl;
    cout << "-------    -------" << endl;
    for (auto source : primsMst) 
        for (auto target : primsMst[source.first])
            cout << source.first << "          " << target << endl;

    // Test djikstrasAlgorithm()

    // Set up adjacency list
    char vertexNames[8] = { 'S', 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
    vector<tuple<char, int, bool>> vertices;
    for (auto name : vertexNames) {
        tuple<char, int, bool> vertex{ name, numeric_limits<int>::max(), false };
        vertices.push_back(vertex);
    }

    AdjacencyList<tuple<char, int, bool>> djikstrasList(vertices);
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
    cout << "Testing djikstrasAlgorithm():" << endl;
    //djikstrasAlgorithm(djikstrasList.getList(), vertices);
    //cout << "Distance from S of all vertices generated by Djikstra's Algorithm:" << endl;
    //cout << "Vertex:    Distance:" << endl;
    //cout << "-------    ---------" << endl;
}