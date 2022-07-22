class Solution
{
    void topodfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                topodfs(it, adj, vis, st);
            }
        }
        st.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int> st;
	    vector<int> vis(V+1, 0);
	    for(int i = 0; i < V; i++){
	        if(!vis[i]){
	            topodfs(i, adj, vis, st);
	        }
	    }
	    vector<int> ans;
	    while(!st.empty()){
	        int node = st.top();
	        st.pop();
	        ans.push_back(node);
	    }
	    return ans;
	}
};

/// BFS traversal:
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> indegree(V+1, 0);
	    for(int i = 0; i < V; i++){
	        for(auto it : adj[i]) indegree[it]++;
	    }
	    queue<int> q;
	    for(int i = 0; i < V; i++){
	        if(!indegree[i]) q.push(i);
	    }
	    
	    vector<int> ans;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        for(auto it : adj[node]){
	            indegree[it]--;
	            if(!indegree[it]) q.push(it);
	        }
	    }
	    return ans;
	}
};
