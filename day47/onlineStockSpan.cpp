class StockSpanner {
public:
    stack<pair<int, int>> st;
    
    int idx;
    StockSpanner() {
        idx = 0;
    }
    
    int next(int price) {
        if(st.size() == 0 && idx == 0){
            st.push({price, idx});
            idx++;
            return 1;
        } 
        while(!st.empty() && price >= st.top().first)
            st.pop();
        int ans = idx+1;
        if(!st.empty()) ans = idx- st.top().second;
        st.push({price, idx});
        idx++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
