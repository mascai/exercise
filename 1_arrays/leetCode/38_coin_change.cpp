/*

*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        vector<int> dp(amount+1, -1);
        for (auto coin : coins) {
            if (coin <= amount) {
                dp[coin] = 1;
            }
        }

        for (int i = 1; i <= amount; ++i) {
            if (dp[i] == -1) {
                int minCoin = INT_MAX;
                bool flag = false;
                for (auto coin : coins) {
                    if (coin <= amount and i - coin >= 0 and dp[i - coin] != -1) {
                        flag = true;
                        minCoin = min(minCoin, dp[i - coin]);
                    }
                }
                if (flag) {
                    dp[i] = minCoin + 1;
                }
            }
        }
        
        return dp[amount];
    }
};
