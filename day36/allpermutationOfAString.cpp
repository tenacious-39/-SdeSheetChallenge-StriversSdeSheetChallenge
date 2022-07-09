/// Brute force:
class Solution {
    void permute(vector<int> &nums, int n, vector<int> &ds, vector<bool> mp, vector<vector<int>> &ans){
        if(ds.size() == n){
            ans.push_back(ds);
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(!mp[i]){
                mp[i]  = true;
                ds.push_back(nums[i]);
                permute(nums, n, ds, mp, ans);
                mp[i] = false;
                ds.pop_back();
            }
        }
        
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> ds;
        vector<bool> mp(n, false);
        permute(nums,n, ds, mp, ans);
        return ans;
    }
};


/// My approah:
class Solution {
    void permute(vector<int> &nums, int start, int end, vector<vector<int>> &ans){
        if(start == end){
            ans.push_back(nums);
            return;
        }
        
        for(int i = start; i < end; i++){
            swap(nums[start], nums[i]);
            permute(nums, start+1, end, ans);
            swap(nums[start], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        permute(nums, 0, n, ans);
        return ans;
    }
};
