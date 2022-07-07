class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 0) return res;
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            vector<int> tmp(3);
            int front = i+1, back = n-1;
            while(front < back){
                if(nums[i]+nums[front]+nums[back] > 0) back--;
                else if(nums[i]+nums[front]+nums[back] < 0) front++;
                else {
                    tmp[0] = nums[i];
                    tmp[1] = nums[front];
                    tmp[2] = nums[back];
                    res.push_back(tmp);
                    while(front < back && nums[front] == tmp[1]) front++;
                    while(front < back && nums[back] == tmp[2]) back--;
                }
            }
            while(i+1 < n && nums[i+1] == nums[i]) i++;
        }
        return res;
    }
};
