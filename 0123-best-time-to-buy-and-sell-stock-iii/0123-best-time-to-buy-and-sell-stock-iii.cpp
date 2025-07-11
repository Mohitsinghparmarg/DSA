class Solution {
public:
    int Solve(int index, int buy, int capacity, vector<int>& prices,
              vector<vector<vector<int>>>& dp) {
        if (capacity == 0 || index == prices.size()) {
            return 0;
        }
        if (dp[index][buy][capacity] != -1) {
            return dp[index][buy][capacity];
        }
        if (buy) {
            return dp[index][buy][capacity] =
                       max(-prices[index] +
                               Solve(index + 1, 0, capacity, prices, dp),
                           0 + Solve(index + 1, 1, capacity, prices, dp));
        } else {
            return dp[index][buy][capacity] =
                       max(prices[index] +
                               Solve(index + 1, 1, capacity - 1, prices, dp),
                           0 + Solve(index + 1, 0, capacity, prices, dp));
        }
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(
            prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return Solve(0, 1, 2, prices, dp);
    }
};