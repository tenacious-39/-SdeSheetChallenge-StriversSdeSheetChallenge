int f(int n, int k, vector<vector<int>> &dp){
        if(k == 0 or k == 1) return k;
        if(n == 1) return k;
        
        if(dp[n][k] != -1) return dp[n][k];
        
        int mini = INT_MAX, x, res;
        for(x=1;x<=k;x++){
            res = max(f(n-1,x-1,dp),f(n, k-x, dp));
            if(res < mini) mini=res;
        }
        
        dp[n][k]=mini+1;
        return mini+1;
    }
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return f(n, k, dp);
    }
