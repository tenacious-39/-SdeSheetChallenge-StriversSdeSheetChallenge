#include<bits/stdc++.h>
vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    int n = v.size();
    vector<vector<int>>ans;
    for (int num = 0; num < (1 << n); num++) {
        vector<int> ds;
        for (int i = 0; i < n; i++) {
            //check if the ith bit is set or not
            if (num & (1 << i)) {
                ds.push_back(v[i]);
            }
        }
        if (ds.size() > 0) {
            ans.push_back(ds);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
