#include <iostream>
using namespace std;

int Josephus(int n, int k) {
    k--;  // convert to 0-based step
    int arr[n];

    for (int i = 0; i < n; i++) arr[i] = 1;  // all alive

    int cnt = 0, cut = 0, num = 1;

    while (cnt < n - 1) {
        while (num <= k) {
            cut++;
            cut %= n;
            if (arr[cut] == 1) num++;
        }
        num = 1;
        arr[cut] = 0;
        cnt++;
        cut++;
        cut %= n;
        while (arr[cut] == 0) {
            cut++;
            cut %= n;
        }
    }

    return cut + 1;  // convert back to 1-based index
}

int main() {
    int n = 25, k = 2;
    cout << "Survivor: " << Josephus(n, k) << endl;
    return 0;
}
