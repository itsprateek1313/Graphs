#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adjList;

    // Adds an edge between two vertices
    void addEdge(int u, int v, bool direction) {
        adjList[u].push_back(v);
        if (direction == 0) { // For undirected graph
            adjList[v].push_back(u);
        }
    }

    // Prints the adjacency list
    void printAdjList() {
        for (auto node : adjList) {
            cout << node.first << " -> ";
            for (auto neighbour : node.second) {
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }

    // BFS traversal of the graph
    void bfsTraversal(int source, unordered_map<int, bool> &visited) {
        queue<int> q;
        // Initial state
        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            // Process the current node
            int frontNode = q.front();
            q.pop();
            cout << frontNode << " ";

            // Process the neighbors
            for (auto neighbour : adjList[frontNode]) {
                if (!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        cout << endl;
    }
};

int main() {
    // Create a graph
    Graph g;
    
    // Test data: add edges for an undirected graph
    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(1, 4, 0);
    g.addEdge(2, 5, 0);
    g.addEdge(2, 6, 0);

    // Print the adjacency list for verification
    cout<<"Adjacency List: "<<endl;
    g.printAdjList();
    cout<<endl;
    
    // Initialize visited map and run BFS for all components
    unordered_map<int, bool> visited;
    int n = 7;  // Number of nodes
     
    cout<<"BFS Traversal: "<<endl;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            g.bfsTraversal(i, visited);
        }
    }

    return 0;
}
