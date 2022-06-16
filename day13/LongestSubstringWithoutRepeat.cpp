// Best approach using map:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0, r = 0, n = s.size();
        int len = 0;
        while(l <= n-1 && r <= n-1){
            if(mp.find(s[r]) == mp.end()){
                len = max(len, r-l+1);
            }
            else if(mp[s[r]] < l) len = max(len, r-l+1);
            else{
                l = mp[s[r]]+1;
                
                len = max(len, r-l+1);
            }
            
            mp[s[r]] = r; r++;
        }
        return len;
    }
};

// Optimised approach using set data structure:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int l = 0, r = 0, n = s.size();
        int len = 0;
        while(l <= n-1 && r <= n-1){
            if(!st.count(s[r])){
                len = max(len, r-l+1);
            } else{
                while(st.count(s[r])){
                    st.erase(s[l++]);
                }
                
                len = max(len, r-l+1);
            }
            
            st.insert(s[r++]);
        }
        return len;
    }
};
