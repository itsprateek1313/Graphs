#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // Since the graph is undirected
    }

    bool dfs(int node, int parent, unordered_map<int, bool> &visited) {
        visited[node] = true;

        for (auto neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                // Recursively call DFS for unvisited neighbors
                if (dfs(neighbor, node, visited)) {
                    return true;
                }
            } else if (neighbor != parent) {
                // If visited neighbor is not the parent, there's a cycle
                return true;
            }
        }

        return false;
    }

    bool detectCycle() {
        unordered_map<int, bool> visited;

        // Check for cycles in each disconnected component
        for (auto i : adjList) {
            if (!visited[i.first]) {
                if (dfs(i.first, -1, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1);  // This edge creates a cycle

    if (g.detectCycle()) {
        cout << "Cycle detected" << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

    return 0;
}
