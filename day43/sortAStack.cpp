void sortit(stack<int> &st, int ele){
    if(st.empty() or (!st.empty() and ele > st.top())){
        st.push(ele);
        return;
    } else{
        int tmp = st.top();
        st.pop();
        sortit(st, ele);
        st.push(tmp);
    }
}
void stackSort(stack<int> &st){
    if(!st.empty()){
        int ele = st.top();
        st.pop();
        stackSort(st);
        sortit(st, ele);
        
    } else return;
}
void sortStack(stack<int> &stack)
{
	// Write your code here
    if(!stack.empty()) stackSort(stack);
    else return;
}
