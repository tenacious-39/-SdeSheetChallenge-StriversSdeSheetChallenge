// coding ninjas:
#include<bits/stdc++.h>
int maxProfit(vector<int> &val, vector<int> &wt, int n, int w)
{
	// Write your code here
    vector<vector<int>> dp(n, vector<int>(w+1, 0));
    for(int W = wt[0]; W<=w; W++) dp[0][W] = val[0];
    
    for(int ind=1;ind<n; ind++){
        for(int W = 0; W<=w; W++){
            int notTake = 0+dp[ind-1][W];
            int take = INT_MIN;
            if(wt[ind] <= W){
                take = val[ind]+dp[ind-1][W-wt[ind]];
            }
            dp[ind][W] = max(take, notTake);
        }
    }
    return dp[n-1][w];
}

// leetcode:
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        int zero, one;
        for(auto s : strs){
            one = zero = 0;
            for(auto ch : s){
                if(ch == '0') zero++;
                else one++;
            }
            
            for(int i = m; i >= zero; i--){
                for(int j = n; j >= one; j--){
                    dp[i][j] = max(dp[i][j], 1+dp[i-zero][j-one]);
                }
            }
        }
        return dp[m][n];
    }
};
