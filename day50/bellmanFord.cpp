
vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        // Code here
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        
        //relaxation:
        for(int i = 1; i <= V-1; i++){
            for(auto it : adj){
                if(dist[it[0]]+it[2] < dist[it[1]]){
                    dist[it[1]] = dist[it[0]]+it[2];
                }
            }
        }
  
        /* //One more relaxation to check
        //if this contains a negative cycle:
        bool flag = false;
        for(auto it : adj){
                if(dist[it[0]]+it[2] < dist[it[1]]){
                    flag = true;
                    break;
                }
       }
       
       //if(flag) then this graph contains negative cycle:
       */
        
        return dist;
    }
