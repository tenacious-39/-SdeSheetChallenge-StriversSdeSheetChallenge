class Solution {
    void func(int ind, vector<int> &a, int target, vector<vector<int>> &ans, vector<int> &ds){
        if(target == 0) ans.push_back(ds);
        for(int i = ind; i < a.size() && target > 0; i++){
            if(i != ind && a[i] == a[i-1]) continue;
            ds.push_back(a[i]);
            func(i+1, a, target-a[i], ans, ds);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        vector<int> ds;
        func(0, a, target, ans, ds);
        return ans;
    }
};
