

// My code 1:
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]) return nums[i];
        }
        return -1;
    }
};


// My code 2:
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> mp;
        for(auto it : nums){
            if(mp[it] == 1){
                return it;
            }
            mp[it]++;
        }
        return -1;
    }
};
