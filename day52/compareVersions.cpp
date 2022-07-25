#include<bits/stdc++.h>
void print(vector<long long> &ans){
    for(auto it : ans) cout << it << " ";
    cout << endl;
}
int compare(string &a, string &b){
       int n = a.size(), m = b.size();
    if(n > m) return 1;
    if(m > n) return -1;
    
    for(int i = 0; i < n; i++){
        if(a[i] < b[i]) return -1;
        else if(a[i] > b[i]) return 1;
    } return 0;
}
int compareVersions(string a, string b) 
{
    // Write your code here
    int n = a.size(), m = b.size();
    vector<string> numa, numb;
    string tmp = "";
    for(auto it : a){
        if(it == '.'){
            numa.push_back(tmp);
            tmp = "";
        } else tmp += it;
    } numa.push_back(tmp);
    tmp = "";
    
    for(auto it : b){
        if(it == '.'){
            numb.push_back(tmp);
            tmp = "";
        } else tmp += it;
    } numb.push_back(tmp);
    
    n = numa.size(); m = numb.size();
    if(n < m)for(int i=n;i<m;i++) numa.push_back("0");
    if(m < n) for(int i=m;i<n;i++) numb.push_back("0");
    
   // print(numa); print(numb);
    for(int i = 0; i < max(m, n); i++){
        if(compare(numa[i], numb[i]) == 1)  return 1;
        else if(compare(numa[i], numb[i]) == -1) return -1;
    } return 0;
}
