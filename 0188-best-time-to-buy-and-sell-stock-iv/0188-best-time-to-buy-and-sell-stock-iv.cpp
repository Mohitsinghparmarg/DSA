class Solution {
public:
    int Solve(int index, int transaction, int k, vector<int>& prices,
              vector<vector<int>>& dp) {
        if (index == prices.size() || transaction == 2 * k) {
            return 0;
        }
        if (dp[index][transaction] != -1)
            return dp[index][transaction];

        if (transaction % 2 == 0) {
            dp[index][transaction] =
                max(-prices[index] +
                        Solve(index + 1, transaction + 1, k, prices, dp),
                    0 + Solve(index + 1, transaction, k, prices, dp));
        } else {
            dp[index][transaction] =
                max(prices[index] +
                        Solve(index + 1, transaction + 1, k, prices, dp),
                    0 + Solve(index + 1, transaction, k, prices, dp));
        }
        return dp[index][transaction];
    }

    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k, -1));
        return Solve(0, 0, k, prices, dp);
    }
};