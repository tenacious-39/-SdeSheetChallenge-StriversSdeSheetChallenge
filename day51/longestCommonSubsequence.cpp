// memoization:

class Solution {
public:
    int f(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp){
        // Base case:
        if(ind1 < 0 or ind2 < 0) return 0;
        
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        if(s1[ind1] == s2[ind2]) return dp[ind1][ind2] = 1+f(ind1-1, ind2-1, s1, s2, dp);
        return dp[ind1][ind2] = 0+max(f(ind1, ind2-1, s1, s2, dp), f(ind1-1, ind2, s1, s2, dp));
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        int ind1 = n-1, ind2 = m-1;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(ind1, ind2, s1, s2, dp);
    }
};

// tabulation:
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(s1[ind1-1] == s2[ind2-1]) {
                    dp[ind1][ind2] = 1+dp[ind1-1][ind2-1];
                } else{
                    dp[ind1][ind2] = 0+max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
                }
            }
        } return dp[n][m];
    }
};
