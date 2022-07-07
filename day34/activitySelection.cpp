#include<bits/stdc++.h>
static bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}
int maximumActivities(vector<int> &start, vector<int> &end) {
    // Write your code here.
    vector<pair<int, int>> meet;
    int n = start.size();
    for(int i = 0; i < n; i++){
        meet.push_back({start[i], end[i]});
    }
    sort(meet.begin(), meet.end(), cmp);
    int ans = 1;
    int limit = meet[0].second;
    for(int i = 1;i<n;i++){
        if(meet[i].first >= limit){
            limit = meet[i].second;
            ans++;
        }
    }return ans;
}
