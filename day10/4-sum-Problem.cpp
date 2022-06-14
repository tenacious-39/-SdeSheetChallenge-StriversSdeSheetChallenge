// Optimized approach:
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size()==0) return res;
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
           
            for(int j = i+1; j < n; j++){
                
                vector<int> quad(4);
                int target_2 = target-nums[j]-nums[i];
                int front = j+1, back = n-1;
                while(front < back){
                    int sum = nums[front]+nums[back];
                  
                    if(target_2 > sum) front++;
                    else if(target_2 < sum) back--;
                    else{
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[front];
                        quad[3] = nums[back];
                        res.push_back(quad);
                        while(front < back and nums[front] == quad[2]) front++;
                        while(front < back and nums[back]==quad[3]) back--;
                    }
                }
                //print(quad);
                 while(j+1 < n and nums[j]==nums[j+1]) j++;
            }
            while(i+1 < n and nums[i]==nums[i+1]) i++;
        }
        return res;
    }
};

// Brute force ---> TC O(N^3logN) sort --> 3 pointer+binary Search
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> st;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j+1; k < n; k++){
                    vector<int> tmp(4);
                    tmp[0] = nums[i]; tmp[1] = nums[j]; tmp[2] = nums[k];
                    long long rem = target-nums[i]-nums[j]-nums[k];
                    int low = k+1, high = n-1, mid;
                    while(low <= high){
                        mid = (low+high)/2;
                        if(nums[mid]*1LL == rem){
                            
                            tmp[3] = nums[mid];
                        
                            st.insert(tmp);
                            break;
                        }  else if(nums[mid]*1LL > rem) high = mid-1;
                        else low = mid+1;
                    }
                  
                }
            }
        }
        vector<vector<int>> ans;
        for(auto it : st) ans.push_back(it);
        return ans;
    }
};
