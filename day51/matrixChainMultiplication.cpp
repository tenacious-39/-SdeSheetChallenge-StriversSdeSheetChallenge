
int matrixMultiplication(vector<int> &arr, int n)
{
    // Write your code here.
    int dp[n][n];
    for(int i=1;i<n;i++) dp[i][i] = 0;
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<n;j++){
            int mini = 1e9;
            for(int k=i;k<j;k++){
                int need = arr[i-1]*arr[j]*arr[k]+dp[i][k]+dp[k+1][j];
                mini = min(mini, need);
            } dp[i][j] = mini;
        }
    } return dp[1][n-1];
}
