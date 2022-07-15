class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto it : s){
            if(st.empty() or it == '(' or it == '{' or it == '[') st.push(it);
            else if((it == ')' && st.top() == '(') or (it == '}' && st.top() == '{') or (it == ']' && st.top() == '[')) st.pop();
            else return false;
        }
        if(!st.empty()) return false;
        return true;
    }
};
