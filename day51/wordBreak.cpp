bool check(string s1, string &s2){
        if(s1.size() != s2.size()) return false;
        int n = s1.size();
        int i = 0;
        while(i < n){
            if(s1[i] != s2[i]) return false; i++;
        } return true;
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        int n = A.size();
        vector<int> dp(n+1, false);
        dp[n] = true;
        for(int i=n-1;i>=0;i--){
            for(auto it : B){
                if(i+it.size() <= n and check(A.substr(i, it.size()), it))
                    dp[i] = dp[i+it.size()];
                if(dp[i]) break;
            }
        }
        return dp[0] == false? 0 : 1;
    }
