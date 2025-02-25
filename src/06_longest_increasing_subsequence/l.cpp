#include <bits/stdc++.h>

using namespace std;


int backtrack(vector<int> &arr, int i, int previous, vector<int>& sequence, vector<int>& temp) {
    if (i >= arr.size()) {
        if (temp.size() > sequence.size()) {
            sequence = temp;
        }
        return 0;
    }

    int take = 0;
    int dontTake = backtrack(arr, i + 1, previous, sequence, temp);

    if (arr[i] > previous) {
        temp.push_back(arr[i]);
        take = 1 + backtrack(arr, i + 1, arr[i], sequence, temp);
        temp.pop_back(); 
    }

    return max(take, dontTake);
}



int main() {
    vector<int> a = {7, 2, 9, 1, 11, 5, 13, 19, 3, 20};

    // Backtracking LIS
    vector<int> backtrackSequence, temp;
    int ans = backtrack(a, 0, INT_MIN, backtrackSequence, temp);
    
    cout << "Max length (backtrack): " << backtrackSequence.size() << endl;
    cout << "LIS (backtrack): ";
    for (int num : backtrackSequence) cout << num << " ";
    cout << endl;

   

    return 0;
}
