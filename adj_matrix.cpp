#include <bits/std++.h>
using namespace std;

int main(){
    // No. of nodes
    int n;
    cout << "Enter the number of nodes: " << endl;
    cin >> n;
    // No. of edges
    int e;
    cout << "Enter the number of edges: " cin >> e;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
    }
    return 0;
}

