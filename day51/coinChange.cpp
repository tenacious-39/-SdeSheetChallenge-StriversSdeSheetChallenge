//coding ninjas:
#include<vector>
long f(int ind, int T, int* a, vector<vector<long>> &dp){
    if(ind == 0){
        return (long)(T%a[ind] == 0);
    }
    if(dp[ind][T] != -1) return dp[ind][T];
    long notTake = f(ind-1, T, a, dp);
    long take = 0;
    if(a[ind] <= T) take = f(ind, T-a[ind], a, dp);
    return dp[ind][T] = notTake+take;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long>> dp(n, vector<long>(value+1, -1));
    
    return f(n-1, value, denominations, dp);
}

// leetcode:
class Solution {
public:
    int f(int ind, int T, vector<int> &a, vector<vector<long>> &dp){
        if(ind == a.size() or T <= 0){
            if(T == 0) return 0;
            else return INT_MAX-1;
        }
        if(dp[ind][T] != -1) return dp[ind][T];
        long notTake = 0+f(ind+1, T, a, dp);
        long take = INT_MAX;
        if(a[ind] <= T){ 
            take = 1+f(ind, T-a[ind], a, dp);
            return dp[ind][T] = min(notTake, take);
        } 
        return dp[ind][T] = notTake;
        
    }
    int coinChange(vector<int>& coins, int value) {
        int n = coins.size();
        vector<vector<long>> dp(n, vector<long>(value+1, -1));
        long ans = f(0, value, coins, dp);
        if(ans == INT_MAX-1) return -1;
        return ans;
    }
};
