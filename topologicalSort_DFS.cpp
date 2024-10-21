#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    // Adds an edge between two vertices
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v); // Directed edge from u to v
    }

    // Prints the adjacency list
    void printAdjList()
    {
        for (auto node : adjList)
        {
            cout << node.first << " -> ";
            for (auto neighbour : node.second)
            {
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }
    
    // Topological sort using DFS
    void topoSortUsingDFS(int source, unordered_map<int, bool> &visited, stack<int>& ans)
    {
        visited[source] = true;
        
        for (auto neighbour : adjList[source])
        {
            if (!visited[neighbour])
            {
                topoSortUsingDFS(neighbour, visited, ans);
            }
        }
        ans.push(source);// wapis aate wqt node ko stack me store krlo
    }
};

int main()
{
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

    unordered_map<int, bool> visited;
    stack<int> ans;

    // Topological Sort
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.topoSortUsingDFS(i, visited, ans);
        }
    }

    // Print the topological sort
    cout << "\nTopological Sort: ";
    while (!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }

    return 0;
}
