/// My approach:
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        int maxi = nums[0];
        int idx = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > maxi){
                nums[idx+1] = nums[i];
                k++;
                idx++;
                maxi = nums[idx];
            }
        }
        return k;
    }
};


// Cleaner code:
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int j = 1; j < nums.size(); j++){
            if(nums[j] != nums[i]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};
