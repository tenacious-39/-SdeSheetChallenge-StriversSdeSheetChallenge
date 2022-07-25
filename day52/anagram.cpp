#include<bits/stdc++.h>
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    if(str1.size() != str2.size()) return false;
    if(str1 == str2) return true;
    unordered_map<char,int> mp;
    for(auto it : str2) mp[it]++;
    for(auto it : str1){
        if(mp.find(it) == mp.end()) return false;
    } return true;
}
