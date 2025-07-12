class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2 * k + 1, 0));
        for (int index = prices.size() - 1; index >= 0; index--) {
            for (int transaction = 2 * k - 1; transaction >= 0; transaction--) {
                if (transaction % 2 == 0) {
                    dp[index][transaction] =
                        max(-prices[index] + dp[index + 1][transaction + 1],
                            0 + dp[index + 1][transaction]);
                } else {
                    dp[index][transaction] =
                        max(prices[index] + dp[index + 1][transaction + 1],
                            0 + dp[index + 1][transaction]);
                }
            }
        }
        return dp[0][0];
    }
};