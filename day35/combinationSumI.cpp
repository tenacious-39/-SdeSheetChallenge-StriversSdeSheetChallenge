

//// my approach:
class Solution {
    void func(vector<int> &a, int target, int n, int ind, int sum, vector<int> &ds, vector<vector<int>> &ans){
        if(ind == n or sum >= target){
            if(sum == target){
                ans.push_back(ds);
            }
            return;
        }
        
        ds.push_back(a[ind]);
        func(a, target, n, ind, sum+a[ind], ds, ans);
        ds.pop_back();
        func(a, target, n, ind+1, sum, ds, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = candidates.size();
        func(candidates, target, n, 0, 0, ds, ans);
        return ans;
    }
};
