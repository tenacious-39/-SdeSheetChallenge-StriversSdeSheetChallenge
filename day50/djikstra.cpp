class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[S] = 0;
        pq.push(make_pair(dist[S], S));
        while(!pq.empty()){
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                if(it[1]+distance < dist[it[0]]){
                    dist[it[0]] = it[1]+distance;
                    pq.push(make_pair(dist[it[0]], it[0]));
                }
            }
        }
        return dist;
    }
};
