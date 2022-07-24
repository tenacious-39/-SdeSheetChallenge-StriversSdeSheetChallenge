int maxIncreasingDumbbellsSum(vector<int> &arr, int n)
{
	// Write your code here
    int maxi = arr[0];
        vector<int> dp(n);
        dp[0] = arr[0];
        for(int i = 1; i < n; i++){
            dp[i] = arr[i];
            int sum = INT_MIN;
            for(int j = 0; j<i; j++){
                if(arr[i] > arr[j]){
                    if(dp[j]+arr[i] > sum){
                        sum = dp[j]+arr[i];
                        dp[i] = sum;
                    }
                }
            }
            maxi = max(maxi, dp[i]);
        } 
        return maxi;
}
