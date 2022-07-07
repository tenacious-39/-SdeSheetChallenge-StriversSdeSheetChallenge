class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0;
        int cnt = 0;
        for(auto it : nums){
            if(it == 0){
                maxOnes = max(maxOnes, cnt);
                cnt = 0;
            } else cnt++;
        }
        maxOnes = max(maxOnes, cnt);
        return maxOnes;
    }
};
