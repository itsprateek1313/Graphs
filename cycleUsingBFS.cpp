#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adjList;

    // Adds an edge between two vertices
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // Since the graph is undirected
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
    // Detect cycle using BFS for a specific component
    bool detectCycleUsingBFS(int source, unordered_map<int, bool> &visited) {
        unordered_map<int, int> parent;
        queue<int> q;

        // Initial steps
        q.push(source);
        visited[source] = true;
        parent[source] = -1;

        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();

            for (auto neighbour : adjList[frontNode]) {
                if (!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = frontNode;
                } else if (neighbour != parent[frontNode]) {
                    // A cycle is found if the neighbor is visited and not the parent
                    return true;
                }
            }
        }

        return false;
    }

    // Function to detect a cycle in the entire graph (disconnected graph case)
    bool detectCycleInDisconnectedGraph() {
        unordered_map<int, bool> visited;

        // Check for cycles in each disconnected component
        for (auto node : adjList) {
            if (!visited[node.first]) {
                if (detectCycleUsingBFS(node.first, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    // Create a graph
    Graph g;

    // Test data: add edges for an undirected graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    // Add another disconnected component with a cycle
    g.addEdge(7, 8);
    g.addEdge(8, 9);
    g.addEdge(9, 7);

    // Print the adjacency list for verification
    cout << "Adjacency List: " << endl;
    g.printAdjList();
    cout << endl;

    // Initialize visited map and run BFS for all components
    unordered_map<int, bool> visited;
    int n = 10;  // Number of nodes


    // Detect cycles in the graph
    if (g.detectCycleInDisconnectedGraph()) {
        cout << "Cycle detected in the graph" << endl;
    } else {
        cout << "No cycle detected in the graph" << endl;
    }

    return 0;
}
