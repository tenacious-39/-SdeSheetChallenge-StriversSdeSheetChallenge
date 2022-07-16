vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    vector<int> ans(n);
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() and st.top() >= A[i]) st.pop();
        if(!st.empty()) ans[i] = st.top();
        else ans[i] = -1;
        st.push(A[i]);
    }
    return ans;
}
