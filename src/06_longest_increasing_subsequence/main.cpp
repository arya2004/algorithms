#include <bits/stdc++.h>

using namespace std;


// recursion
int backtrack(vector<int> & arr, int i, int previous){
    if(i >= arr.size()){
        return 0;
    }
    int take = 0;
    int dontTake = backtrack(arr, i + 1, previous);
    if(arr[i] > previous){
        take = 1 + backtrack(arr, i + 1, arr[i]);
    }

    return max(take, dontTake);

}


//dp memoization

vector<vector<int>> dp;

    


int solve(vector<int>& arr, int i, int prevIndex) {
    if (i >= arr.size()) {
        return 0;
    }
    if (dp[i][prevIndex + 1] != -1) return dp[i][prevIndex + 1];

    int dontTake = backtrack(arr, i + 1, prevIndex);
    int take = 0;
    if (prevIndex == -1 || arr[i] > arr[prevIndex]) {
        take = 1 + solve(arr, i + 1, i);
    }

    return dp[i][prevIndex + 1] = max(take, dontTake);
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    dp.resize(n, vector<int>(n + 1, -1));
    return solve(nums, 0, -1);
}

int main() {
    
    vector<int> a = {7,2,9,1,11,5,13,19,3,20};
    int ans = backtrack(a, 0, INT_MIN);

    cout << "maxl: " << ans << endl;

    
    int andDp = lengthOfLIS(a);
    cout << "dp solution: " << andDp << endl;
    

    return 0;
}