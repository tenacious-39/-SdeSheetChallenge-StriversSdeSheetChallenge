class Solution {
public:
    double myPow(double x, int n) {
        if(n == INT_MIN and x > 1.0) return 0.0;
        double ans = 1;
        int tmp = n;
        n = abs(n);
        while(n > 0){
            if(n&1){
                n--;
                ans *= x;
            } else{
                x *= x;
                n /= 2;
            }
        } 
        return tmp < 0? 1/ans : ans;
    }
};
