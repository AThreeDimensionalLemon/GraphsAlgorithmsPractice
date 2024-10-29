// 
// Name: main.cpp
// Author: Eisig Liang
// Last update: 28 October 2024
// Purpose: Create an adjacency list for Djikstra's Algorithm
// Notices:
//     1. Carries the same issues as its parent class
//     2. Built purely for completing the assignment; usage for other graph algorithms not tested
//     3. This was harder than making those linked lists. No wonder I see memes hating on C. 
// 

#pragma once
#include <iostream>
#include <map>
#include <vector>
using namespace std;


class DjikstraAdjacencyList
{
public: //Won't be a security issue; only being used as a template
    struct edge {
        int weight;
        bool isVisited;
    };
    struct djikstra {
        char vertex;
        int distance;
        bool isVisited; //Method in primsAlgorithm() is boilerplate-y; dropping for this method
    };

protected:
    map<djikstra, //Vertex
        map<djikstra, //Connected vertex
        edge>> list;
    bool isDirected;

public:
    DjikstraAdjacencyList(vector<djikstra> vertices, bool isDirected = false);
    void addEdge(djikstra source, djikstra target, int weight = 1);
    map<djikstra, map<djikstra, edge>> getList();
};

DjikstraAdjacencyList::DjikstraAdjacencyList(vector<djikstra> vertices, bool inIsDirected) {

    for (djikstra vertex : vertices) {
        map<djikstra, edge> edgesMap;
        list.insert({ vertex, edgesMap });
    }

    isDirected = inIsDirected;
}

void DjikstraAdjacencyList::addEdge(djikstra source, djikstra target, int weight) {
    edge sourceTargetEdge{ weight, false };
    list[source][target] = sourceTargetEdge;

    if (not isDirected) {
        edge targetSourceEdge{ weight, false };
        list[target][source] = targetSourceEdge;
    }
}


map<djikstra, map<djikstra, typename DjikstraAdjacencyList::edge>>DjikstraAdjacencyList::getList() {
    return list;
}