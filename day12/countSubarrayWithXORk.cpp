int Solution::solve(vector<int> &A, int B) {
    map<int, int> mp;
    int cnt = 0, xorr = 0;
    for(auto it : A){
        xorr ^= it;
        if(xorr == B) cnt++;
        if(mp.find(xorr^B) != mp.end()){
            cnt += mp[xorr^B];
        }
        mp[xorr]++;
    }
    return cnt;
}
