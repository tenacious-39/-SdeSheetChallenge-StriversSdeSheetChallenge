#include<bits/stdc++.h>
bool findCycle(int s, vector<int> adj[], vector<int> &vis){
	queue<pair<int, int>> q;
    q.push({s, -1});
    vis[s] = 1;
    while(!q.empty()){
		int node = q.front().first;
        int par = q.front().second;
        q.pop();
        for(auto it : adj[node]){
            if(!vis[it]){
                q.push({it, node});
                vis[it] = 1;
            }
            else if(par != it) return true;
        }
	}
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int> vis(n+1, 0);
    vector<int> adj[n+1];
    for(auto it : edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    
    for(int i =1; i <= n; i++){
        if(!vis[i]){
            if(findCycle(i, adj, vis)) return "Yes";
        }
    }
    return "No";
}
