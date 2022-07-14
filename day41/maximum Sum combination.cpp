struct ds{
    int val, i, j;  
};
struct cmp{
    bool operator()(struct ds a, struct ds b){
        return a.val < b.val;
    }
};
vector<int> Solution::solve(vector<int> &a, vector<int> &b, int C) {
    int n = a.size();
    priority_queue<struct ds, vector<struct ds>, cmp> pq;
    vector<int> ans;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    set<pair<int,int>> ind;
    
    pq.push({a[n-1]+b[n-1], n-1, n-1});
    ind.insert({n-1, n-1});
    while(ans.size() != C){
        struct ds node = pq.top();
        pq.pop();
        ans.push_back(node.val);
        int I = node.i, J = node.j;
        if(I > 0 && ind.count({I-1, J}) == 0){
            pq.push({a[I-1]+b[J], I-1, J});
            ind.insert({I-1, J});
        }
        if(J > 0 && ind.count({I, J-1}) == 0){
            pq.push({a[I]+b[J-1], I, J-1});
            ind.insert({I, J-1});
        }
    }
    return ans;
}
