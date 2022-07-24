/// Optimised space:
class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1);
        int maxi = INT_MIN;
        for(int ind = 0; ind < n; ind++){
            for(int prev_ind = 0; prev_ind < ind; prev_ind++){
                if(arr[ind] > arr[prev_ind]){
                    dp[ind] = max(dp[ind], 1+dp[prev_ind]);
                }
            }
            maxi = max(maxi, dp[ind]);
        } return maxi;
    }
};

// Using binary search:
#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> dp;
    dp.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i] > dp.back())
            dp.push_back(arr[i]);
        else{
            int ind = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
            dp[ind] = arr[i];
        }
    }
    return dp.size();
}
