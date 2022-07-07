int findMinimumCoins(int amount) 
{
    // Write your code here
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = 9;
    
    int ans = 0;
    for(int i = n-1; i >= 0 ;i--){
        if(amount >= coins[i]){
            ans += amount/coins[i];
            amount %= coins[i];
        }
    } return ans;
}
