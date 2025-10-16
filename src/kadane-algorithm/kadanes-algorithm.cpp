#include <bits/stdc++.h>

using namespace std;


int kadance(vector<int> &nums){
    int ans = INT_MIN;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        ans = max(ans, sum);
        if(sum < 0)
            sum = 0;
    }

    return ans;
    
}

int main(){

    //vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    vector<int> arr = {-2, -3, -4, -1, -2, -1, -5, -3};
    
    cout << kadance(arr);

    return 0;
}