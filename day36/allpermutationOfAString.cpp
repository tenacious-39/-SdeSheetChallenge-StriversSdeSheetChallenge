


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
