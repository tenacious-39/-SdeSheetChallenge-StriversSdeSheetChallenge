
class Solution {
    void dfs(int node, vector<int> &vis, vector<int> &ans, vector<int> adj[]){
        vis[node] = 1;
        ans.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]) dfs(it, vis, ans, adj);
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V, 0);
        vector<int> ans;
        dfs(0, vis, ans, adj);
        return ans;
    }
};

