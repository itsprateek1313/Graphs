#include <bits/stdc++.h>
using namespace std;

// Function to perform BFS and find the shortest path

bfsShortestPath







int main() {
    int n = 6;  // Number of nodes in the graph
    vector<vector<int>> graph(n);

    // Example graph (undirected)
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 4};
    graph[3] = {1, 5};
    graph[4] = {1, 2, 5};
    graph[5] = {3, 4};

    int source = 0, target = 5;
    vector<int> path = bfsShortestPath(graph, source, target, n);

    if (!path.empty()) {
        cout << "Shortest path from " << source << " to " << target << ": ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No path exists between " << source << " and " << target << endl;
    }

    return 0;
}
