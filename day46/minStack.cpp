/// Best approach:
class MinStack {
public:
    stack<long long> st;
    long long mini;
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int value) {
        long long val = value;
        if(st.empty()){
            st.push(val*1LL);
            mini = val;
        } else{
            if(val < mini){
                st.push(2*val*1LL - mini);
                mini = val*1LL;
            }
            else{
                st.push(val*1LL);
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        
        long long ele = st.top();
        if(ele < mini){
            mini = 2*mini-ele;
        }
        st.pop();
    } 
    
    int top() {
        long long ele = st.top();
        if(ele < mini) return mini;
        return ele;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

///1st approach:
class MinStack {
public:
    stack<pair<int,int>> st;
    int mini;
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        mini = min(mini, val);
        st.push({val, mini});
    }
    
    void pop() {
        st.pop();
        if(!st.empty()) mini = st.top().second;
        else mini = INT_MAX;
    }
    
    int top() {
        int ans = st.top().first;
        return ans;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
