// Optimal approach:
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
       unordered_map<int, int> mp;
        int ans = INT_MIN;
        for(auto it : nums) mp[it]++;
        for(auto it : nums){
            if(mp[it-1] == 0){
                int cnt = 0;
                while(mp[it++] > 0 && cnt <= nums.size()) cnt++;
                ans= max(ans, cnt);
            }
        } return ans;
    }
};

// optimal approach 2::
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
       set<int> st;
        int ans = INT_MIN;
        for(auto it : nums) st.insert(it);
        for(auto it : nums){
            if(st.count(it-1) == 0){
                int cnt = 1;
                int num = it;
                while(st.count(num+1)) cnt++, num++;
                ans= max(ans, cnt);
            }
        } return ans;
    }
};
// My approach:
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n==0) return 0;
        int ans = INT_MIN;
        int cnt = 1;
        for(int i = 1;i < n; i++){
            if(abs(nums[i]-nums[i-1])==1) cnt++;
            else if(abs(nums[i]-nums[i-1]) !=0){
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};
