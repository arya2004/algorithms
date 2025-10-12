#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

int i, j, k, a, b, u, v, n, m = 1;
int min_cost = 0;
const int INF = 999; 


std::vector<int> parent;
std::vector<std::vector<int>> cost;

int find(int i) {
    if (parent[i] == 0)
        return i;
    
    return parent[i] = find(parent[i]); 
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    std::cout << "Enter the number of vertices: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Invalid number of vertices.\n";
        return 1;
    }

    parent.resize(n + 1, 0); 
    
    cost.resize(n + 1, std::vector<int>(n + 1));

    std::cout << "Enter the cost adjacency matrix (use 0 for no connection):\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (!(std::cin >> cost[i][j])) {
                std::cerr << "Input error.\n";
                return 1;
            }
            if (cost[i][j] == 0 && i != j) 
                cost[i][j] = INF;
            else if (i == j) 
                cost[i][j] = INF;
        }
    }

    std::cout << "\nThe edges of Minimum Spanning Tree are:\n";

    clock_t start = clock();

    
    while (m < n) {
        int min = INF; 

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        
      
        if (min == INF) {
             std::cout << "Graph is not connected.\n";
             break;
        }

        
        u = find(u);
        v = find(v);

        if (uni(u, v)) {
            std::cout << m++ << " edge (" << a << "," << b << ") =" << min << "\n";
            min_cost += min;
        }

        cost[a][b] = cost[b][a] = INF;
    }

    std::cout << "\nMinimum Cost: " << min_cost << "\n";
    clock_t end = clock();
    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";

    return 0;
}