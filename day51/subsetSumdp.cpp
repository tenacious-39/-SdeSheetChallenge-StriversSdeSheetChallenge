class Solution {
public:
    bool f(int ind, int T, int n, vector<int> &nums, vector<vector<int>> &dp){
        if(ind < 0 or T <= 0){
            if(T == 0) return true;
            return false;
        }
        
        if(dp[ind][T] != -1){
            if(dp[ind][T]) return true;
            return false;
        }
        
        bool notTake = f(ind-1, T, n, nums, dp);
        bool take = false;
        if(nums[ind] <= T) take = f(ind-1, T-nums[ind], n, nums, dp);
        return dp[ind][T] = (take or notTake);
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(totalSum %2 == 1) return false;
        int target = totalSum/2;
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        if(f(n-1, target, n, nums, dp)) return true;
        return false;
    }
};
