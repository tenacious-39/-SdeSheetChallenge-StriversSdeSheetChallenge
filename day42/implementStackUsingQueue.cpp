// Optimized:

class MyStack {
    queue<int> q;
    int cnt;
public:
    MyStack() {
        cnt = 0;
    }
    
    void push(int x) {
        q.push(x);
        for(int i = 0; i < cnt; i++){
            q.push(q.front());
            q.pop();
        }
        cnt++;
    }
    
    int pop() {
        int ans = q.front();
        q.pop();
        cnt--;
        return ans;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return cnt == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


------------------------------------------------------------------------------------------------------------------------------------
class MyStack {
    queue<int> q;
    int cnt;
public:
    MyStack() {
        cnt = 0;
    }
    
    void push(int x) {
        queue<int> tmp;
        tmp.push(x);
        while(!q.empty()){
            tmp.push(q.front());
            q.pop();
        }
        q = tmp;
        cnt++;
    }
    
    int pop() {
        int ans = q.front();
        q.pop();
        cnt--;
        return ans;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return cnt == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
