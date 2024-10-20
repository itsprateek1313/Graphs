#include <bits/stdc++.h>
using namespace std;

// Unweighted directed/undirected graphs

class Graph{
public:
    unordered_map<int, list<int>> adjList;
    void addEdge(int u, int v, bool direction){
        adjList[u].push_back(v);
        if (direction == 0){
            adjList[v].push_back(u);
        }
    }
    // unordered_map<int,list<int>> adjList;
    // node: adjList => node = each value of adjList
    // node.first = int
    // node.second = list of neighbours
    void printAdjList() {
        for (auto node : adjList){
            cout << node.first << "-> ";
            for (auto neighbour : node.second){
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    // Creating a graph object
    Graph g;

    // Adding edges (u, v, direction) => direction: 0 for undirected, 1 for directed
    g.addEdge(0, 1, 0); // Edge between 0 and 1, undirected
    g.addEdge(1, 2, 0); // Edge between 1 and 2, undirected
    g.addEdge(2, 3, 1); // Edge between 2 and 3, directed
    g.addEdge(3, 4, 1); // Edge between 3 and 4, directed
    g.addEdge(4, 0, 1); // Edge between 4 and 0, directed

    // Printing the adjacency list
    g.printAdjList();

    return 0;
}