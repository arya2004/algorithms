#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <utility>


using Pair = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max(); 


void dijkstra(int V, const std::vector<std::vector<Pair>>& adj, int src) {
    
    std::vector<int> dist(V + 1, INF); 
    
    
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;

  
    dist[src] = 0;
    pq.push({0, src});


    while (!pq.empty()) {
     
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

   
        if (d > dist[u]) {
            continue;
        }

     
        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

         
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

  
    std::cout << "\nShortest distances from source vertex " << src << ":\n";
    for (int i = 1; i <= V; ++i) {
        std::cout << "Vertex " << i << ": ";
        if (dist[i] == INF) {
            std::cout << "Unreachable\n";
        } else {
            std::cout << dist[i] << "\n";
        }
    }
}

int main() {
    int V, E;
    std::cout << "Enter number of vertices (V) and edges (E): ";
    
    if (!(std::cin >> V >> E) || V <= 0 || E < 0) {
        std::cerr << "Invalid input for V or E.\n";
        return 1;
    }


    std::vector<std::vector<Pair>> adj(V + 1);

    std::cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        if (!(std::cin >> u >> v >> weight)) {
            std::cerr << "Input error for edge " << i + 1 << ".\n";
            return 1;
        }
        if (u < 1 || u > V || v < 1 || v > V || weight < 0) {
            std::cerr << "Invalid vertex or negative weight entered.\n";
            return 1;
        }
        
       
        adj[u].push_back({v, weight});
        
    }

    int src;
    std::cout << "Enter the source vertex: ";
    if (!(std::cin >> src) || src < 1 || src > V) {
        std::cerr << "Invalid source vertex.\n";
        return 1;
    }

    dijkstra(V, adj, src);

    return 0;
}