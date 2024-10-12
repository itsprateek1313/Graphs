#include <bits/stdc++.h>
using namespace std;

class Graphs {
    public:
    unordered_map<int, list<pair<int, int>>> adjList;  

    // Function to add an edge to the graph (only undirected edges)
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    // Function to print the adjacency list
    void printAdjList() {
        for (auto i : adjList) {
            cout << i.first << " -> {";
            for (auto p : i.second) {
                cout << " (" << p.first << ", " << p.second << ") ";
            }
            cout << "}" << endl;
        }
    }

    // BFS traversal of the graph
    void bfsTraversal(int source) {
        unordered_map<int, bool> visited;
        queue<int> q;

        // Initial State
        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            // Process the current node
            int frontNode = q.front();
            q.pop();
            cout << frontNode << " ";

            // Process the neighbors
            for (auto neighbour : adjList[frontNode]) {
                int neighbourData = neighbour.first;
                if (visited[neighbourData] == false) {
                    q.push(neighbourData);
                    visited[neighbourData] = true;
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graphs g;

    // Example edges with weights (only undirected edges)
    g.addEdge(1, 2, 10);  // Edge 1 <--> 2 with weight 10
    g.addEdge(1, 3, 5);   // Edge 1 <--> 3 with weight 5
    g.addEdge(2, 3, 2);   // Edge 2 <--> 3 with weight 2
    g.addEdge(3, 4, 1);   // Edge 3 <--> 4 with weight 1
    g.addEdge(4, 5, 3);   // Edge 4 <--> 5 with weight 3

    // Print the adjacency list
    cout << "Adjacency List:" << endl;
    g.printAdjList();
    cout << endl;

    // Perform BFS traversal starting from node 1
    cout << "BFS Traversal starting from node 1:" << endl;
    g.bfsTraversal(1);

    return 0;
}
