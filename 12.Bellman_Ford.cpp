#include <iostream>
#include <climits>
using namespace std;

int* bellmanFord(int V, int edges[][3], int E, int src) {
    // Initialize distance from source to all other vertices as "infinite"
    int* dist = new int[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // Relax all edges V times; use V-1 iterations to calculate shortest path
    // and an extra iteration to detect negative cycles
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                // If this is the Vth relaxation, then there is a negative cycle
                if (i == V - 1) {
                    delete[] dist;
                    return nullptr;  // Returns nullptr if there's a negative cycle
                }
                // Update shortest distance to node v
                dist[v] = dist[u] + wt;
            }
        }
    }
    return dist;
}

int main() {
    int V = 5;  // Number of vertices
    int E = 5;  // Number of edges
    int edges[5][3] = { {1, 3, 2}, {4, 3, -1}, {2, 4, 1}, {1, 2, 1}, {0, 1, 5} };

    int src = 0;
    int* dist = bellmanFord(V, edges, E, src);

    if (dist == nullptr) {
        cout << "Graph contains a negative-weight cycle" << endl;
    } else {
        for (int i = 0; i < V; i++) {
            cout << dist[i] << " ";
        }
        cout << endl;
    }

    // Clean up dynamically allocated memory
    delete[] dist;
    return 0;
}

// *********OUTPUT********
//   0 5 6 6 7 
