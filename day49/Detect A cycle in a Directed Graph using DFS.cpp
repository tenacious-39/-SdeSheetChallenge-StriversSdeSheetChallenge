bool cycleDfs(int node, vector<int> &vis, vector<int> &dfsvis, vector<int> adj[]){
        vis[node] = 1;
        dfsvis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(cycleDfs(it, vis, dfsvis, adj)) return true;
            }
            else if(dfsvis[it]) return true;
        }
        dfsvis[node] = 0;
        return false;
    }
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    vector<int> adj[n+1];
    vector<int> vis(n+1, 0);
    vector<int> dfsvis(n+1, 0);
    
    for(auto it : edges){
        adj[it.first].push_back(it.second);
    }
    
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            if(cycleDfs(i, vis, dfsvis, adj)) return 1;
        }
    } return 0;
}
