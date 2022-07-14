#include<bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    vector<int> ans;
    for(int i = 0; i < k; i++){
        for(auto it : kArrays[i]){
            ans.push_back(it);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
--------------------------------------------------------------------------------------------------
  
  #include<bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < k; i++){
        for(auto it : kArrays[i]){
            pq.push(it);
        }
    }
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
