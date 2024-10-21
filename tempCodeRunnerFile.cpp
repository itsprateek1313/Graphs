#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    // Adds a directed edge between two vertices
    void addEdge(int u, int v){
        adjList[u].push_back(v); // Directed edge from u to v
    }

    // Function to calculate the in-degree of each node
    //Har node pe traverse kro,neighbour pe jao aur ++ krdo bcz there is an edge
    unoredered_map<int,int> calculateInDegree(int n) {
        unoredered_map<int,int> inDegree;
        // Traverse the adjacency list
        for (auto i : adjList) {
            for (auto neighbor : i.second)     {
                inDegree[neighbor]++; // Increment in-degree for each neighbor
            }
        }
        return inDegree;
    }
};

int main(){
    // Create a graph
    Graph g;

    // Number of vertices
    int n = 6;

    // Adding edges to the graph (DAG)
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    // Calculate in-degree of each node
    unoredered_map<int,int> inDegree = g.calculateInDegree(n);

    // Print in-degree of each node
    cout << "In-degree of each node:" << endl;
    for(auto data:inDegree){
        cout<<data.first<<": "<<data.second<<endl;
    }
    return 0;
}
