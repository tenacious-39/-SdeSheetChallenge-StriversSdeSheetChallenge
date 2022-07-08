//// Optimised approach:
class Solution {
    void getSubset(vector<int> &nums, int n, int idx, vector<int> &ds, vector<vector<int>> &ans){
        ans.push_back(ds);
        for(int i = idx; i < n; i++){
            if(i != idx && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            getSubset(nums, n, i+1, ds, ans);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        getSubset(nums, n, 0, ds, ans);
        return ans;
    }
};



/// My approach:
class Solution {
    void getSubset(vector<int> &nums, int n, int idx, vector<int> &ds, set<vector<int>> &ans){
        if(idx == n){
            ans.insert(ds);
            return;
        }
        ds.push_back(nums[idx]);
        getSubset(nums, n, idx+1, ds, ans);
        ds.pop_back();
        getSubset(nums, n, idx+1, ds, ans);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        vector<int> ds;
        getSubset(nums, n, 0, ds, ans);
        vector<vector<int>> answer;
        for(auto it : ans) answer.push_back(it);
        return answer;
    }
};
