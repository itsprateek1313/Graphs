#include <bits/stdc++.h>
using namespace std;

class Graphs{
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    // Function to add an edge to the graph (only undirected edges)
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    // Function to print the adjacency list
    void printAdjList(){
        for (auto i : adjList)
        {
            cout << i.first << " -> {";
            for (auto p : i.second)
            {
                cout << " (" << p.first << ", " << p.second << ") ";
            }
            cout << "}" << endl;
        }
    }

    // BFS traversal of the graph
    void bfsTraversal(int source, unordered_map<int, bool> &visited){

        queue<int> q;
        // Initial State
        q.push(source);
        visited[source] = true;
        while (!q.empty()){
            // Process the current node
            int frontNode = q.front();
            q.pop();
            cout << frontNode << " ";
            // Process the neighbors
            for (auto neighbour : adjList[frontNode]) {
                int neighbourData = neighbour.first;
                if (visited[neighbourData] == false)
                {
                    q.push(neighbourData);
                    visited[neighbourData] = true;
                }
            }
        }
        cout << endl;
    }

    void dfsTraversal(int source, unordered_map<int, bool> &visited){
        // Solve one case
        visited[source] = true;
        cout << source << " ";
        // Rest recursion will handle
        for (auto neighbour : adjList[source]){
            int neighbourData = neighbour.first;
            if (visited[neighbourData] == false){
                dfsTraversal(neighbourData, visited);
            }
        }
    }

    // Is there any path exists between two nodes using DFS --> O(V+E)
    bool anyPathExists(int source, int destination, unordered_map<int, bool> &visited)
    {
        // BASE CASE
        if (source == destination)
            return true;
        visited[source] = true;
        for (auto neighbour : adjList[source])
        {
            if (visited[neighbour.first] == false)
            {
                bool result = anyPathExists(neighbour.first, destination, visited);
                if (result)
                    return true;
            }
        }
        return false;
    }

    void pathsBetweenNodes(int source, int destination, unordered_map<int, bool> &visited, vector<int> &currentPath, vector<vector<int>> &paths){
        // Add the current node to the path
        currentPath.push_back(source);
        // BASE CASE: If source is equal to destination, add the path to the list of paths
        if (source == destination){
            paths.push_back(currentPath); // Push the current path to paths
        }
        else{
            // Mark the current node as visited
            visited[source] = true;
            // Explore all unvisited neighbors
            for (auto neighbour : adjList[source])
            {
                if (!visited[neighbour.first]){
                    pathsBetweenNodes(neighbour.first, destination, visited, currentPath, paths);
                }
            }
            // Backtrack: Unmark the node as visited
            visited[source] = false;
        }
        // Backtrack: Remove the current node from the path
        currentPath.pop_back();
    }
};


int main()
{
    Graphs g;
    unordered_map<int, bool> visited;

    // Example edges with weights (only undirected edges)
    g.addEdge(1, 2, 10); // Edge 1 <--> 2 with weight 10
    g.addEdge(1, 3, 5);  // Edge 1 <--> 3 with weight 5
    g.addEdge(2, 3, 2);  // Edge 2 <--> 3 with weight 2
    g.addEdge(3, 4, 1);  // Edge 3 <--> 4 with weight 1
    g.addEdge(4, 5, 3);  // Edge 4 <--> 5 with weight 3
    g.addEdge(6, 7, 5);  // Edge 6 <--> 7 with weight 5

    // bool ans = g.anyPathExists(6,7,visited);
    // if(ans){
    //     cout<<"Yes Path exists"<<endl;
    // }
    // else{
    //     cout<<"No valid path exists"<<endl;
    // }

    vector<vector<int>> paths;
    vector<int> currentPath;
    g.pathsBetweenNodes(1, 5, visited, currentPath, paths);
    // Print all paths
    for (const auto &path : paths)
    {
        for (int node : path)
        {
            cout << node << " ";
        }
        cout << endl;
    }
    // Print the adjacency list
    // cout << "Adjacency List:" << endl;
    // g.printAdjList();
    // cout << endl;
    // Perform BFS traversal starting from node 1
    // cout << "BFS Traversal starting from node 1:" << endl;
    // g.bfsTraversal(1,visited);
    // cout << "DFS Traversal starting from node 1:" << endl;
    // g.dfsTraversal(1,visited);
    return 0;
}
