class Solution {
public:

    int helper(vector<int>& coins, int amount,vector<int>& dp) {

        if (amount < 0) {
            return INT_MAX;
        }
        if (amount == 0) {
            return 0;
        }
        if(dp[amount]>0){
            return dp[amount];
        }


        int minCoin = INT_MAX;

        for (int j = 0; j < coins.size(); j++) {

            int data = helper(coins, amount - coins[j],dp);

            if (data != INT_MAX) {
                minCoin = min(minCoin, data + 1);
            }
        }
        dp[amount]=minCoin;
        return minCoin;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,0);
        int ans = helper(coins, amount,dp);

        if (ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};