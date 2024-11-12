import heapq

def add_edge(graph, u, v, weight):
    graph[u].append((v, weight))
    graph[v].append((u, weight))

def prim_mst(graph, vertices):
    pq = []
    heapq.heappush(pq, (0, 0))  # Start from vertex 0 with weight 0
    visited = [False] * vertices
    mst_cost = 0

    while pq:
        weight, u = heapq.heappop(pq)
        if visited[u]:
            continue
        visited[u] = True
        mst_cost += weight

        for neighbor, edge_weight in graph[u]:
            if not visited[neighbor]:
                heapq.heappush(pq, (edge_weight, neighbor))

    return mst_cost

# Driver code
num_vertices = 5
graph = [[] for _ in range(num_vertices)]

add_edge(graph, 0, 1, 2)
add_edge(graph, 0, 3, 6)
add_edge(graph, 1, 2, 3)
add_edge(graph, 1, 3, 8)
add_edge(graph, 1, 4, 5)
add_edge(graph, 2, 4, 7)
add_edge(graph, 3, 4, 9)

print("Minimum cost of the MST:", prim_mst(graph, num_vertices))


# *****************************OUTPUT************************
# Minimum cost of the MST: 16
