#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>


const long long INF = 1e9; 
void floydWarshall(int V, std::vector<std::vector<long long>>& dist) {
    for (int k = 1; k <= V; ++k) {
      
        for (int i = 1; i <= V; ++i) {
          
            for (int j = 1; j <= V; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    
                  
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        
                     
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    
    std::cout << "\nChecking for negative cycles...\n";
    for (int i = 1; i <= V; ++i) {
        if (dist[i][i] < 0) {
            std::cout << "  WARNING: Negative cycle detected at vertex " << i << " (dist = " << dist[i][i] << ").\n";
            
        }
    }
}


void printDistanceMatrix(int V, const std::vector<std::vector<long long>>& dist) {
    std::cout << "\nAll-Pairs Shortest Path Matrix:\n";
    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j) {
            if (dist[i][j] == INF) {
                std::cout << "INF\t";
            } else {
                std::cout << dist[i][j] << "\t";
            }
        }
        std::cout << "\n";
    }
}

int main() {
    int V;
    std::cout << "Enter the number of vertices (V): ";
    if (!(std::cin >> V) || V <= 0) {
        std::cerr << "Invalid number of vertices.\n";
        return 1;
    }

    std::vector<std::vector<long long>> dist(V + 1, std::vector<long long>(V + 1, INF));

    std::cout << "Enter the initial weights of the edges.\n";
    std::cout << "For no direct edge, you can enter 'INF' or '0' (it will be treated as INF).\n";
    std::cout << "Format: u v weight (enter -1 -1 -1 to stop input):\n";

  
    int u, v;
    long long weight;
  
    for (int i = 1; i <= V; ++i) {
        dist[i][i] = 0;
    }

   
    while (std::cin >> u >> v >> weight && (u != -1 || v != -1 || weight != -1)) {
        if (u < 1 || u > V || v < 1 || v > V) {
            std::cerr << "Warning: Skipping edge with out-of-bounds vertices (" << u << ", " << v << ").\n";
            continue;
        }
        if (weight == 0 && u != v) {
             std::cout << "Warning: Edge weight 0 treated as INF (no edge).\n";
             continue; 
        }
        
        
        dist[u][v] = weight;

      
    }

    floydWarshall(V, dist);

    printDistanceMatrix(V, dist);

    return 0;
}