class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = nums[0];
        int sum = 0;
        for(auto it : nums){
            sum += it;
            if(sum > maxi){
                maxi = sum;
            }
            if(sum < 0) sum = 0;
        }
        return maxi;
    }
};
