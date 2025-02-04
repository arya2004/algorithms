#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Brute Force Approach (O(n^2))
int findMajorityBruteForce(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[i])
                count++;
        }
        if (count > n / 2)
            return arr[i];
    }
    return -1; 
}

// Sorting Approach (O(n log n))
int findMajoritySorting(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int candidate = arr[arr.size() / 2]; 
    int count = 0;
    for (int num : arr) {
        if (num == candidate)
            count++;
    }
    return (count > arr.size() / 2) ? candidate : -1;
}

// Boyer-Moore Voting Algorithm (O(n))
int findMajorityBoyerMoore(vector<int>& arr) {
    int candidate = 0, count = 0;
    

    for (int num : arr) {
        if (count == 0)
            candidate = num;
        count += (num == candidate) ? 1 : -1;
    }

    return candidate;
}

int main() {
  
    vector<int> arr = {
        3, 3, 4, 2, 4, 4, 2, 4, 4, 4, 4, 4, 4, 3, 3, 4, 4, 4, 2, 4, 4, 4, 
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
    };

   
    cout << "Brute Force: " << findMajorityBruteForce(arr) << endl;
    cout << "Sorting: " << findMajoritySorting(arr) << endl;
    cout << "Boyer-Moore: " << findMajorityBoyerMoore(arr) << endl;

    return 0;
}
