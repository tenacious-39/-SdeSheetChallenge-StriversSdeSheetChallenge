#include<vector>
int f(int ind, vector<int> &price, int n, vector<vector<int>> &dp){
    if(ind == 0){
        return (n*price[ind]);
    }
    if(dp[ind][n] != -1) return dp[ind][n];
    int rodLength = ind+1;
    int notTake = f(ind-1, price, n, dp);
    int take = INT_MIN;
    if(rodLength <= n) take = price[ind]+f(ind, price, n-rodLength, dp);
    return dp[ind][n] = max(take, notTake);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return f(n-1, price, n, dp);
}
