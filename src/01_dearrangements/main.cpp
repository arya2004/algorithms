#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
HINT: use inclusion exclusion principle for prooving that logN times

*/

bool is_dearrangement(const vector<int>& perm) {
    for (int i = 0; i < perm.size(); ++i) {
        if (perm[i] == i + 1) { 
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> v;
    for(int i = 1; i < 6; i++){
        v.push_back(i);
    }
    vector<vector<int>> permutations;
    vector<vector<int>> dearrangements;

 
    do {
        permutations.push_back(v);
        if (is_dearrangement(v)) {
            dearrangements.push_back(v);
        }
    } while (next_permutation(v.begin(), v.end()));



    cout << "\nAll dearrangements:\n";
    for (const auto& dearr : dearrangements) {
        for (int num : dearr) {
            cout << num << " ";
        }
        cout << "\n";
    }


    double total_permutations = permutations.size();
    double total_dearrangements = dearrangements.size();
    double probability = total_dearrangements / total_permutations;

    cout << "\nTotal permutations: " << total_permutations << endl;
    cout << "Total dearrangements: " << total_dearrangements << endl;
    cout << "Probability of dearrangement: " << probability << endl;

    double inverse_probability = 1 / probability;
    cout << "Inverse of probability: " << inverse_probability << endl;

    cout << "Euler's number (e): " << exp(1) << endl;

    return 0;
}
