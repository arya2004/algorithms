#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <utility>
#include <tuple>
const int INF = std::numeric_limits<int>::max();
using Edge = std::pair<int, int>; 
using AdjPair = std::pair<int, int>; 
void prims(int V, const std::vector<std::vector<AdjPair>>& adj, int start_node) {
    std::vector<int> min_weight(V + 1, INF);
   
    std::vector<bool> in_mst(V + 1, false);
    
    std::vector<int> parent(V + 1, 0);
    
    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;

    min_weight[start_node] = 0;
    pq.push({0, start_node}); // {weight, vertex}

    int mst_cost = 0;
    int edges_count = 0;

  
    while (!pq.empty() && edges_count < V) {
       
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (in_mst[u]) {
            continue;
        }

        in_mst[u] = true;
        mst_cost += w;
     
        if (u != start_node) {
            std::cout << "Edge (" << parent[u] << ", " << u << ") - Weight: " << w << "\n";
            edges_count++;
        }

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!in_mst[v] && weight < min_weight[v]) {
                min_weight[v] = weight;
                parent[v] = u; // u is the new parent of v in the MST
                pq.push({min_weight[v], v});
            }
        }
    }

    if (edges_count == V - 1) {
        std::cout << "\nMinimum Spanning Tree Cost: " << mst_cost << "\n";
    } else {
        std::cout << "\nGraph is not connected. Found MST for the connected component.\n";
    }
}

int main() {
    int V, E;
    std::cout << "Enter number of vertices (V) and edges (E): ";
   
    if (!(std::cin >> V >> E) || V <= 0 || E < 0) {
        std::cerr << "Invalid input for V or E.\n";
        return 1;
    }

    std::vector<std::vector<AdjPair>> adj(V + 1);

    std::cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        if (!(std::cin >> u >> v >> weight)) {
            std::cerr << "Input error for edge " << i + 1 << ".\n";
            return 1;
        }
        if (u < 1 || u > V || v < 1 || v > V) {
            std::cerr << "Invalid vertex entered.\n";
            return 1;
        }

        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); 
    }

    int start_node;
    std::cout << "Enter the starting vertex: ";
    if (!(std::cin >> start_node) || start_node < 1 || start_node > V) {
        std::cerr << "Invalid starting vertex.\n";
        return 1;
    }

    std::cout << "\nEdges of the Minimum Spanning Tree:\n";
    prims(V, adj, start_node);

    return 0;
}