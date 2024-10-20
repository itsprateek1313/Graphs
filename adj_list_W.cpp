#include <bits/stdc++.h>
using namespace std;
// Weighted directed/undirected graphs
class Graph{
public:
    unordered_map<int, list<pair<int, int>>> adjList;
    void addEdge(int u, int v, int weight, bool direction){
        adjList[u].push_back(make_pair(v, weight));
        // adjList[u].push_back({v,weight});
        if (direction == 0){
            adjList[v].push_back(make_pair(v, weight));
        }
    }
    // unordered_map<int,list<int>> adjList;
    // node: adjList => node = each value of adjList
    // node.first = int
    // node.second = list of neighbours
    void printAdjList(){
        for (auto node : adjList){
            cout << node.first << "-> ";
            for (auto neighbour : node.second){
                cout << "(" << neighbour.first << "," << neighbour.second << "), ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;

    // Adding edges (u, v, weight, direction) => direction: 0 for undirected, 1 for directed
    g.addEdge(1,2,2,0);
    g.addEdge(2,3,1,0);
    g.addEdge(2,4,6,0);
    g.addEdge(1,3,3,0);
    g.addEdge(3,4,0,0);
   

    // Printing the adjacency list
    g.printAdjList();
    return 0;
}