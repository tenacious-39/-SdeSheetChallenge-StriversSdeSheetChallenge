// Optimized:
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int n = nums.size();
        vector<int> ans(2);
        
        for(int i = 0; i < n; i++){
            ans[0] = i;
            int rem = target - nums[i];
            if(mp.find(rem) != mp.end()){
                ans[1] = mp[rem];
                break;
            } else{
                mp[nums[i]] = i;
            }
        }
        return ans;
    }
};


// brute force:
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int n = nums.size();
        for(int i = 0; i < n; i++){
            ans[0] = i;
            for(int j = i+1; j < n; j++){
                if(nums[i] + nums[j] == target){
                    ans[1] = j;
                    break;
                }
            }
            if(ans[0] != -1 && ans[1] != -1) break;
        } return ans;
    }
};
