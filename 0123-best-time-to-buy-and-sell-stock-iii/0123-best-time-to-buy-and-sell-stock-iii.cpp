class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(
            prices.size() + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int index = prices.size() - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int capacity = 1; capacity <= 2; capacity++) {
                    if (buy) {
                        dp[index][buy][capacity] =
                            max(-prices[index] + dp[index + 1][0][capacity],
                                0 + dp[index + 1][1][capacity]);
                    } else {
                        dp[index][buy][capacity] =
                            max(prices[index] + dp[index + 1][1][capacity - 1],
                                0 + dp[index + 1][0][capacity]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};