int getStudents(vector<int> &a, int barrier){//, int B){
    int sum = 0;
    int cnt = 1;
    for(auto it : a){
        if(it > barrier) return INT_MAX;
        if(sum+it > barrier){
            cnt++;
            sum = it;
        } else sum += it;
    } 
    return cnt;
}
int Solution::books(vector<int> &a, int B) { 
    if(B > a.size()) return -1;
    int low = INT_MAX, high = 0;
    for(auto it : a){
        low = min(low, it);
        high += it;
    }
    while(low <= high){
        int mid = (low+high) >> 1;
        int cnt = getStudents(a, mid);
        if(cnt <= B) high = mid-1;
        else low = mid+1; 
    }  return low;
}
