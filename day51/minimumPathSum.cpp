class Solution {
public:
    int f(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(i == grid.size()-1 && j == grid[0].size()-1) return grid[i][j];
    if(i >= n or j >= m) return 1e9;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = grid[i][j]+min(f(i+1, j, n,m,grid,dp),f(i, j+1, n,m,grid,dp));
                         
}
    int minPathSum(vector<vector<int>>& grid) {
        int i = 0, j = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return f(i, j, n, m, grid, dp);
    }
};
