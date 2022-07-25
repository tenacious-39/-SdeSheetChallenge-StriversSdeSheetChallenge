class Solution {
public:
    void f(int &l, int &r, string &s){
        int n = s.size();
        while(l >= 0 and r < n){
            if(s[l] == s[r]) {
                l--; r++;
            } else break;
        }
    }
    string longestPalindrome(string s) {
        if(s.size() == 1) return s;
        int maxLen = 1;
        int n = s.size();
        int startInd = 0;
        for(int i = 0; i < n-1; i++){
            int l = i, r = i;
            f(l, r, s);
            int len = r-l-1;
            if(len > maxLen){
                maxLen = max(maxLen, len);
                startInd = l+1;
            }
            
        }
        for(int i = 0; i < n-1; i++){
            int l=i,r=i+1;
            f(l,r, s);
            int len = r-l-1;
            if(len > maxLen){
                maxLen = max(maxLen, len);
                startInd = l+1;
            }
        }
        return s.substr(startInd, maxLen);
    }
};
