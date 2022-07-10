bool isSafe(int node, int col, int n, bool graph[101][101], int color[]){
    for(int k = 0; k < n; k++){
        if(k != node and graph[k][node] == 1 and color[k] == col) return false;
    }
    return true;
}
bool solve(int node, int color[], int m, int n, bool graph[101][101]){
    if(node == n) return true;
    
    for(int i = 1; i <= m; i++){
        if(isSafe(node, i, n, graph, color)){
            color[node] = i;
            if(solve(node+1, color, m, n, graph)) return true;
            color[node] = 0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    int color[n] = {0};
    bool ans = solve(0, color, m, n, graph);
    return ans;
}
