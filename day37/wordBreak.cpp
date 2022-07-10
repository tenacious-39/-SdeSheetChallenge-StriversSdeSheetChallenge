const bool isInDic(string s, vector<string> &dic){
    for(auto it : dic){
        if(it.compare(s) == 0) return true;
    }
    return false;
}
void solve(string &s, int ind, string &ds, vector<string> &ans, vector<string> &dic){
    if(ind >= s.size()){
        ans.push_back(ds); 
        return;
    }
    
    for(int i = ind; i < s.size(); i++){
        if(isInDic(s.substr(ind, i-ind+1), dic)){
            string tmp = ds;
            ds += s.substr(ind, i-ind+1) + " ";
            solve(s, i+1, ds, ans, dic);
            ds = tmp;
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    vector<string> ans;
    string ds = "";
    solve(s, 0, ds, ans, dictionary);
    
    return ans;
}
