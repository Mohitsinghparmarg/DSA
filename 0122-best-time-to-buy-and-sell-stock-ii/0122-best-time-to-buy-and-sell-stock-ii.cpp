class Solution {
public:
    int Solve(int index, vector<int>& prices, const bool& buy, int& profit,
              vector<vector<int>>& dp) {

        if (index == prices.size())
            return 0;
        if (dp[index][buy] != -1)
            return dp[index][buy];
        if (buy) {
            profit = max(-prices[index] +
                             Solve(index + 1, prices, false, profit, dp),
                         0 + Solve(index + 1, prices, true, profit, dp));
        } else {
            profit =
                max(prices[index] + Solve(index + 1, prices, true, profit, dp),
                    0 + Solve(index + 1, prices, false, profit, dp));
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        bool buy = true;
        int profit = 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return Solve(0, prices, buy, profit, dp);
    }
};