class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        // Your code here
        map<int, int> mp;
        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(sum == 0) maxi = max(maxi, i+1);
            else if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            } else{
                maxi = max(maxi, i-mp[sum]);
            }
        } return maxi == INT_MIN? 0 : maxi;;
    }
};
