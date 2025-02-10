/*

->  Topological sorting is an ordering of the vertices of a 
    Directed Acyclic Graph (DAG) such that for every 
    directed edge u → v, vertex u appears before v in the ordering.

->  Kahn's Algorithm (BFS) – O(V + E)

*/
#include <bits/stdc++.h>
using namespace std;
vector<int> TopologicalSort(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> indegree(n, 0), res;
    queue<int> q;

    for (int i = 0; i < n; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    // BFS (Kahn's Algorithm)
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        res.push_back(node);
        for (auto adjV : adj[node]) {
            indegree[adjV]--;
            if (indegree[adjV] == 0) q.push(adjV);
        }
    }

    // If result size < n, graph has a cycle (not a DAG)
    return (res.size() == n) ? res : vector<int>();
}

int main() {
    int n, m;
    cin >> n >> m; // Number of nodes and edges
    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;  // Directed edge u -> v
        adj[u].push_back(v);
    }

    vector<int> topoOrder = TopologicalSort(adj);

    if (topoOrder.empty()) {
        cout << "Graph contains a cycle, topological sort not possible.\n";
    } else {
        for (int node : topoOrder) {
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}
