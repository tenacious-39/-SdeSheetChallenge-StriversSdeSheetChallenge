struct node{
    int u;
    int v;
    int wt;
    node(int _u, int _v, int _wt){
        u = _u;
        v = _v;
        wt = _wt;
    }
};

bool cmp(node &a, node &b){
    return a.wt < b.wt;
}
int findPar(int u, vector<int> &parent) {
        if(u == parent[u]) return u; 
        return parent[u] = findPar(parent[u], parent); 
    }
    
    void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
        u = findPar(u, parent);
        v = findPar(v, parent);
        if(rank[u] < rank[v]) {
        	parent[u] = v;
        }
        else if(rank[v] < rank[u]) {
        	parent[v] = u; 
        }
        else {
        	parent[v] = u;
        	rank[u]++; 
        }
    }
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        // Kruskal's Algo:
        
        vector<node> edges;
        for(int i = 0; i < V; i++){
            for(auto it : adj[i]){
                edges.push_back(node(i, it[0], it[1]));
            }
        }
        sort(edges.begin(), edges.end(), &cmp);
        
        vector<int> parent(V);
    	for(int i = 0;i<V;i++) 
    	    parent[i] = i; 
    	vector<int> rank(V, 0);
    	
    	int cost = 0;
    	vector<pair<int,int>> mst; 
    	for(auto it : edges) {
    	    if(findPar(it.v, parent) != findPar(it.u, parent)) {
    	        cost += it.wt; 
    	        mst.push_back({it.u, it.v}); 
    	        unionn(it.u, it.v, parent, rank); 
    	    }
    	}
    	return cost;
    }
