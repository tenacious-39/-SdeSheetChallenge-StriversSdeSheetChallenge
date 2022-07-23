#include<bits/stdc++.h>
void topoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]){
    vis[node] = 1;
    
    for(auto it : adj[node]){
        if(!vis[it]){
            topoSort(it, vis, st, adj);
        }
    } st.push(node);
}

void dfs(int node, vector<int> &vis, vector<int> &ans, vector<int> adj[]){
        vis[node] = 1;
        ans.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]) dfs(it, vis, ans, adj);
        }
}


vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int> ans;
    vector<int> vis(n, 0);
    vector<int> adj[n];
    for(auto it : edges){
        adj[it[0]].push_back(it[1]);
    }
    
    // topoSort:
    stack<int> st;
    for(int i=0; i < n; i++){
        if(!vis[i]) topoSort(i, vis, st, adj);
    }
    
    //transpose Graph:
    vector<int> transpose[n];
    for(int i = 0; i < n; i++){
        vis[i] = 0;
        for(auto it : adj[i]){
            transpose[it].push_back(i);
        }
    }
    
    //dfs:
    vector<vector<int>> res;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            dfs(node, vis, ans, transpose);
            res.push_back(ans);
            ans.clear();
        }
    } return res;
}
