int Solution::findMedian(vector<vector<int> > &a) {
    int n = a.size(), m = a[0].size();
    int meadian = (n*m)/2;
    int low = 1, high = 1e9;
    while(low <= high){
        int mid = (low+high)/2;
        
        // 2nd Binary Search:
       
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int lcol = 0, hcol = m-1;
            while(lcol <= hcol){
               
                int middle = (lcol+hcol)/2;
                
                if(a[i][middle] > mid) hcol = middle-1;
                else lcol = middle+1;
            }
            
            cnt += lcol;
        }
        
        if(cnt <= meadian) low = mid+1;
        else high = mid-1;
    }
    return low;
}
