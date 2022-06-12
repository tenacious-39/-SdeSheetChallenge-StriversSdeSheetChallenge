// Combination:
class Solution {
public:
    int uniquePaths(int m, int n) {
        double num = m+n-2;
        double denom = m-1;
        double ans = 1;
        for(int i = 1; i <= denom; i++){
            ans = ans * (double)(num-denom+i)/(double)(i);
        } return ans;
    }
};


// Recursive DP:
class Solution {
    int countPaths(int i, int j, int m, int n, vector<vector<int>> &dp){
        if(i >= m or j >= n) return 0;
        if(i == m-1 and j == n-1) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        else return dp[i][j] = countPaths(i+1, j, m, n, dp)+countPaths(i, j+1,m,n,dp);
    }
public:
    int uniquePaths(int m, int n) {
        //int path = 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int path = countPaths(0, 0, m, n, dp);
        return path;
    }
};
