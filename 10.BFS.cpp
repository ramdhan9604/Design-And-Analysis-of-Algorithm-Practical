#include <iostream>
#include <queue>
using namespace std;

const int V = 5; // Number of vertices in the graph
const int MAX_EDGES = V; // Maximum edges any vertex can have in an undirected graph

// BFS from given source s
void bfs(int adj[V][MAX_EDGES], int adjSize[], int s) {
    queue<int> q;  
    bool visited[V] = {false};  // Initially mark all vertices as not visited

    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        // Traverse all adjacent vertices of the dequeued vertex
        for (int i = 0; i < adjSize[curr]; i++) {
            int neighbor = adj[curr][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// Function to add an edge to the graph
void addEdge(int adj[V][MAX_EDGES], int adjSize[], int u, int v) {
    adj[u][adjSize[u]++] = v;
    adj[v][adjSize[v]++] = u; // Undirected Graph
}

int main() {
    int adj[V][MAX_EDGES] = {0}; // Adjacency list (2D array)
    int adjSize[V] = {0}; // Array to keep track of the number of adjacent vertices for each vertex

    // Add edges to the graph
    addEdge(adj, adjSize, 0, 1);
    addEdge(adj, adjSize, 0, 2);
    addEdge(adj, adjSize, 1, 3);
    addEdge(adj, adjSize, 1, 4);
    addEdge(adj, adjSize, 2, 4);

    // Perform BFS traversal starting from vertex 0
    cout << "BFS starting from 0: \n";
    bfs(adj, adjSize, 0);

    return 0;
}


// ********************OUTPUT********************
// BFS starting from 0: 
// 0 1 2 3 4
