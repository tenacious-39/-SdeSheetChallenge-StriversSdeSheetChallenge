class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mini = 1, maxi = 1, product = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
                int tmp = maxi;
                maxi = max(nums[i], max(maxi*nums[i], mini*nums[i]));
                mini = min(nums[i], min(tmp*nums[i], mini*nums[i]));
                if(product < maxi) product = maxi;
        }
        if(product == INT_MIN) return 0;
        else return product;
    }
};
