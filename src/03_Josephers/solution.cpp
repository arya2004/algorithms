#include <bits/stdc++.h>
using namespace std;

// Josephus Problem: returns safe position (1-indexed)
int josephus(int n, int k) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = (res + k) % i;
    }
    return res + 1; // convert 0-indexed to 1-indexed
}

int main() {
    int n, k;
    cout << "Enter number of people (n): ";
    cin >> n;
    cout << "Enter step count (k): ";
    cin >> k;

    cout << "Safe position: " << josephus(n, k) << endl;
    return 0;
}
