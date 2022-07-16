// Optimised approach:
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nge;
        int n = nums2.size();
        stack<int> st;
        for(int i = n-1; i >=0; i--){
            if(st.empty()){
                nge[nums2[i]] = -1;
                
            }else{
                while(!st.empty() && st.top() <= nums2[i]){
                    st.pop();
                }
                if(st.empty()) nge[nums2[i]] = -1;
                else nge[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(auto it : nums1) ans.push_back(nge[it]);
        return ans;
    }
};


// Brute force:
// TC = O(N^2), SC = O(N)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto it : nums1) mp[it]++;
        int n = nums2.size();
        for(int i = 0; i < n; i++){
            if(mp[nums2[i]] > 0){
                //cout << nums1[i]
                bool ok = true;
                for(int j = i+1; j < n; j++){
                    if(nums2[j] > nums2[i]){
                        mp[nums2[i]] = nums2[j];
                        ok = false;
                        break;
                    }
                }
                if(ok) mp[nums2[i]] = -1;
            }
        }
        
        for(auto it : nums1) ans.push_back(mp[it]); 
        return ans;
    }
};
