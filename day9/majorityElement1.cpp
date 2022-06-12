// Moore's voting algorithm: (O(N))
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = 0, candidate = 0;
        for(auto it : nums){
            if(vote == 0){
                candidate = it;
            }
            if(it == candidate) vote++;
            else vote--;
        }
        return candidate;
    }
};
// 1st solution:
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int k = n/2;
       sort(nums.begin(), nums.end());
        int prev = nums[0], cnt = 1;
        for(int i =1; i < n; i++){
           // cout << prev << " " << nums[i] << "\n";
            if(nums[i] == prev) cnt++;
            else{
                if(cnt > k) return prev;
                prev = nums[i];
                cnt = 1;
            }
        } 
        //cout << cnt << "nnn\n";
        if(cnt > k) return prev;
        return -1;
    }
};

// 2nd solution
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int k = n/2;
        map<int, int> mp;
        for(auto it : nums) mp[it]++;
        for(auto it : mp){
            if(it.second > k) return it.first;
        } return -1;
    }
};
