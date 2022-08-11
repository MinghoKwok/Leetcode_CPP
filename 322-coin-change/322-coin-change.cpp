class Solution {
    // clarify: amount > coins[0] ?
    // O(c * N)   c is the length of coins
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        
        
        vector<int> dp(amount + 1, -1);
        sort(coins.begin(), coins.end());
        if (amount < coins[0])              // 已经好几次这种需要排序的情形写在排序之前了
            return -1;
        
        for (int i = 0; i < coins[0]; i++) {
            dp[i] = -1;
        }
        
        
        for (int i = coins[0]; i <= amount; i++) {
            for (int c = 0; c < coins.size(); c++) {
                int coin = coins[c];
                if (coin > i)
                    break;
                else if (coin == i) {
                    dp[i] = 1;
                    break;
                } else {
                    if (dp[i - coin] != -1) {
                        if (dp[i] != -1)
                            dp[i] = min(dp[i], 1 + dp[i - coin]);
                        else 
                            dp[i] = 1 + dp[i - coin];
                    }
                        
                }
            }
        }
        
        
        return dp[amount];
    }
};