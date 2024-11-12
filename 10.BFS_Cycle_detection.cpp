#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 100;  // Maximum number of vertices
int adj[MAX_V][MAX_V];  // Adjacency matrix to represent edges

void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1; // Undirected graph
}

bool isCyclicConnected(int s, int V, bool visited[]) {
    // Queue to store (current node, parent node)
    queue<pair<int, int>> q;
    q.push({s, -1});
    visited[s] = true;

    while (!q.empty()) {
        int v = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neighbor = 0; neighbor < V; neighbor++) {
            if (adj[v][neighbor]) {  // There is an edge
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, v});
                } 
                // If visited and not the parent, cycle detected
                else if (neighbor != parent) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool isCyclicDisconnected(int V) {
    // Array to mark visited vertices
    bool visited[MAX_V] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i] && isCyclicConnected(i, V, visited)) {
            return true;
        }
    }
    return false;
}

int main() {
    int V = 4;
    memset(adj, 0, sizeof(adj));  // Initialize adjacency matrix with 0

    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);

    if (isCyclicDisconnected(V))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}

// ***********************OUTPUT*****************
//   Yes
