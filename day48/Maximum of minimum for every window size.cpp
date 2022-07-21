#include<stack>
void print(int arr[], int n){
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}
void clear(stack<pair<int,int>> &st){
    while(!st.empty()) st.pop();
}
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    int  leftSmaller[n], rightSmaller[n];
    stack<pair<int,int>> st;
    for(int i = 0; i < n; i++){
        if(st.empty() and i == 0){
            leftSmaller[i] = -1;
            st.push({a[i], 0});
            continue;
        } 
        while(!st.empty() and st.top().first >= a[i]){
            st.pop();
        }
        if(st.empty()) leftSmaller[i] = -1;
        else leftSmaller[i] = st.top().second;
        st.push({a[i], i});
    }
    clear(st);
    for(int i = n-1; i >= 0; i--){
         if(st.empty() and i == n-1){
            rightSmaller[i] = n;
            st.push({a[i], i});
            continue;
        } 
        while(!st.empty() and st.top().first >= a[i]){
            st.pop();
        }
        if(st.empty()) rightSmaller[i] = n;
        else rightSmaller[i] = st.top().second;
        st.push({a[i], i});
    }
   // print(leftSmaller, n);
    //print(rightSmaller, n);
    vector<int> ans(n, INT_MIN);
    for(int i = 0; i < n; i++){
        int dif = (rightSmaller[i]-leftSmaller[i]-2);
        if(a[i] > ans[dif]) ans[dif] = a[i];
    }
    for(int i = n-2; i>=0; i--){
        if(ans[i] < ans[i+1]) ans[i] = ans[i+1];
    } return ans;
}
