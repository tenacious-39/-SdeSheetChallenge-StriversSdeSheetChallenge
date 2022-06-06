// Most optimized:
//Dutch National Flag Algorithm:
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                low++;
            } else if(nums[mid] == 2){
                swap(nums[mid], nums[high]);
                high--;
                mid--;
            }
            mid++;
        }
    }
};
// Random Solutions:
// 1st Solution:
class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> mp;
        for(auto it : nums) mp[it]++;
        
        nums.clear();
        // for 0
        while(mp[0]--) nums.push_back(0);
        
        // for 1
        while(mp[1]--) nums.push_back(1);
        
        //for 2
        while(mp[2]--) nums.push_back(2);
    }
};


// 2nd Solution:
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        // for 0
        for(int i = 0; i < n; i++){
            if(nums[i] == 0 && i != cnt){
                swap(nums[i], nums[cnt]);
                cnt++;
            } else if(nums[i] == 0 && i == cnt) cnt++;
        }
        for(int i = 0; i < n; i++){
            if(nums[i] == 1 && i != cnt){
                swap(nums[i], nums[cnt]);
                cnt++;
            } else if(nums[i] == 1 && i == cnt) cnt++;
        }
        for(int i = 0; i < n; i++){
            if(nums[i] == 2 && i != cnt){
                swap(nums[i], nums[cnt]);
                cnt++;
            } else if(nums[i] == 2 && i == cnt) cnt++;
        }
    }
};
