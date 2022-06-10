vector<int> Solution::repeatedNumber(const vector<int> &arr) {
    vector<int> buk1, buk2;
    int n = arr.size();
    int num = arr[0];
    for(int i = 1; i < n; i++){
        num = num ^ arr[i];
    }
    for(int i = 1; i <= n; i++) num ^= i;

    int lowbit = num & (-num);
    for(auto it : arr){
        if(lowbit&it){
            buk1.push_back(it);
        } else buk2.push_back(it);
    }
    
    for(int i = 1; i <= n; i++){
        if(lowbit & i) buk1.push_back(i);
        else buk2.push_back(i);
    }
    
    vector<int> ans(2);
    ans[0] = buk2[0];
    ans[1] = buk1[0];
    for(int i = 1; i < buk1.size(); i++) ans[1] ^= buk1[i];
    for(int i = 1; i < buk2.size(); i++) ans[0] ^= buk2[i];
    for(auto it : arr){
        if(it == ans[1]){
            swap(ans[0], ans[1]);
            return ans;
        }
        if(it == ans[0]) return ans;
    } return ans;
}
