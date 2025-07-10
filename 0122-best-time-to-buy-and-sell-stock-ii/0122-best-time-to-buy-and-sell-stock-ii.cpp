class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit = 0;
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[n][0] = 0;
        dp[n][1] = 0;
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    profit = max(-prices[index] + dp[index + 1][0],
                                 0 + dp[index + 1][1]);
                } else {
                    profit = max(prices[index] + dp[index + 1][1],
                                 0 + dp[index + 1][0]);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }
};