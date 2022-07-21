class Solution {
public:
    
    string reverseWords(string s) {
        vector<string> tmp;
        string ans = "";
        for(auto it : s){
           if(it == ' ' && ans != ""){
               tmp.push_back(ans);
               ans = "";
           } else if(it != ' ') ans += it;
        }
        if(ans != "") tmp.push_back(ans);
        //print(tmp);
        reverse(tmp.begin(), tmp.end());
        ans = "";
        int n = tmp.size();
        for(int i = 0; i < n; i++){
            ans += tmp[i];
            if(i != n-1) ans += ' ';
        }
        return ans;
    }
};
