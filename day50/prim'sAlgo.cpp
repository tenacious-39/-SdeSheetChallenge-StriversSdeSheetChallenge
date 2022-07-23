// Brute force:
int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int key[V], parent[V];
        bool mstSet[V];
        
        for(int i = 0; i < V; i++){
            key[i] = INT_MAX;
            parent[i] = -1;
            mstSet[i] = false;
        }
        
        key[0] = 0;
        for(int count = 0; count < V-1; count++){
            
            //find minimum key value:
            int mini = INT_MAX, u;
            
            for(int v = 0; v < V; v++){
                if(mstSet[v] == false && key[v] < mini){
                    mini = key[v];
                    u = v;
                }
            }
            
            mstSet[u] = true;
            for(auto it : adj[u]){
                int v = it[0];
                int weight = it[1];
                if(mstSet[v] == false && weight < key[v]){
                    key[v] = weight;
                    parent[v] = u;
                }
            }
        }
        int sum = 0;
        for(int i = 0; i < V;i++) sum += key[i];
        return sum;
    }


// optimised code:
int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int key[V], parent[V];
        bool mstSet[V];
        
        for(int i = 0; i < V; i++){
            key[i] = INT_MAX;
            parent[i] = -1;
            mstSet[i] = false;
        }
        
        key[0] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            
            //find minimum key value:
            int u = pq.top().second;
            pq.pop();
            
            mstSet[u] = true;
            for(auto it : adj[u]){
                int v = it[0];
                int weight = it[1];
                if(mstSet[v] == false && weight < key[v]){
                    
                    key[v] = weight;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }
        int sum = 0;
        for(int i = 0; i < V;i++) sum += key[i];
        return sum;
    }
