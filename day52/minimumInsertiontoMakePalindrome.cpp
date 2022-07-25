#include<bits/stdc++.h>
vector<int> longPrefixSuffix(string &s){
    int n = s.size();
    vector<int> ans(n, 0);
    for(int i=1;i<n;i++){
        int l = ans[i-1];
        while(l > 0 and s[i] != s[l])
            l = ans[l-1];
        if(s[i] == s[l]) l++;
        ans[i] = l;
    } return ans;
}
int minCharsforPalindrome(string str) {
	// Write your code here.
    string tmp = str;
    reverse(tmp.begin(), tmp.end());
    string newStr = str+'+'+tmp;
    vector<int> res = longPrefixSuffix(newStr);
    int ans = str.size()-res[res.size()-1];
    return ans;
    
	
}
