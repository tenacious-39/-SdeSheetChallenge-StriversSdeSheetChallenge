// Better approach:

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        int prefixMax[n], suffixMax[n];
        
        //Setting prefix array:
        for(int i = 0; i < n; i++){
            if(!i) prefixMax[i] = height[i];
            else{
                prefixMax[i] = (height[i] > prefixMax[i-1])? height[i] : prefixMax[i-1];
            }
        }
        
        //Setting suffix array;
        for(int i = n-1; i >= 0; i--){
            if(i == n-1) suffixMax[i] = height[i];
            else suffixMax[i] = (height[i] > suffixMax[i+1])? height[i] : suffixMax[i+1];
        }
        
        // water calculation:
        int water = 0;
        for(int i = 0; i < n; i++){
            water += min(prefixMax[i], suffixMax[i])-height[i];
        }
        return water;
    }
};
