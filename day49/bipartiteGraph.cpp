class Solution {
    bool check(int i, vector<int> &color, vector<vector<int>>& graph){
            if(color[i] == -1) color[i] = 1;
            for(auto it : graph[i]){
                if(it){
                    if(color[it] == -1){
                        color[it] = 1 - color[i];
                        if(!check(it, color, graph)) return false;
                    }
                    else if(color[it] == color[i]) return false;
                }
            }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size()+1, -1);
        for(int i = 0; i < graph.size(); i++){
            if(color[i] == -1){
                if(!check(i, color, graph))
                    return false;
            }
        }
        return true;
    }
};

// BFS:


class Solution {
    bool check(int i, vector<int> &color, vector<vector<int>>& graph){
        queue<int> q;
        q.push(i);
        color[i] = 1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it : graph[node]){
                if(it){
                    if(color[it] == -1){
                        q.push(it);
                        color[it] = 1 - color[node];
                    }
                    else if(color[it] == color[node]) return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size()+1, -1);
        for(int i = 0; i < graph.size(); i++){
            if(color[i] == -1){
                if(!check(i, color, graph))
                    return false;
            }
        }
        return true;
    }
};
