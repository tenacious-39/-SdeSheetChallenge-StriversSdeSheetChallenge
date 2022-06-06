class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int breakPoint = -1, lastSmall = -1;
        int n = nums.size();
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                breakPoint = i;
                break;
            }
        }
        
        if(breakPoint == -1){
            reverse(nums.begin(), nums.end());
        } else{
            for(int i = n-1; i >= breakPoint; i--){
                if(nums[i] > nums[breakPoint]){
                    lastSmall = i;
                    break;
                }
            }
            swap(nums[breakPoint], nums[lastSmall]);
            reverse(nums.begin()+breakPoint+1, nums.end());
        }
    }
};
