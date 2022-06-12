// Boyer moore voting algo TC O(N):
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size() == 1){
            return nums;
        }
        int k = nums.size()/3;
        int vote1 =0 , vote2 = 0;
        int candidate1 = -1, candidate2 = -1;
        for(auto it : nums){
            if(vote1 != 0 and it == candidate1) vote1++;
            else if(vote2 != 0 and it == candidate2) vote2++;
            else if(vote1 == 0){
                vote1 = 1;
                candidate1 = it;
            } else if(vote2 == 0){
                vote2 = 1;
                candidate2 = it;
            } else{
                vote1--;
                vote2--;
            }
        }
        vector<int> ans;    
        int cnt1 = 0, cnt2 = 0;
        for(auto it : nums){
            if(it == candidate1) cnt1++;
        }
        for(auto it : nums){
            if(it == candidate2) cnt2++;
        }
        if(cnt1 > k) ans.push_back(candidate1);
        if(cnt2 > k && candidate2 != candidate1) ans.push_back(candidate2);
        return ans;
    }
};



// Another approach:
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int k = n/3;
        vector<int> ans;
       sort(nums.begin(), nums.end());
        int prev = nums[0], cnt = 1;
        for(int i =1; i < n; i++){
          
            if(nums[i] == prev) cnt++;
            else{
                if(cnt > k) ans.push_back(prev);
                prev = nums[i];
                cnt = 1;
            }
        } 
       
        if(cnt > k) ans.push_back(prev);
        return ans;
    }
};
