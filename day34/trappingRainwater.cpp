// optimized approach:

class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        
        int l = 0, r = n-1;
        int leftMax = 0, rightMax = 0;
        int water = 0;
        while(l <= r){
            if(a[l] <= a[r]){
                if(a[l] >= leftMax) leftMax = a[l];
                else water += (leftMax-a[l]);
                l++;
            } else{
                if(a[r] >= rightMax) rightMax = a[r];
                else water += (rightMax-a[r]);
                r--;
            }
        }
        return water;
    }
};
