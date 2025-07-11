class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> after(2, vector<int>(3, 0));
        vector<vector<int>> current(2, vector<int>(3, 0));
        for (int index = prices.size() - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int capacity = 1; capacity <= 2; capacity++) {
                    if (buy) {
                        current[buy][capacity] =
                            max(-prices[index] + after[0][capacity],
                                0 + after[1][capacity]);
                    } else {
                        current[buy][capacity] =
                            max(prices[index] + after[1][capacity - 1],
                                0 + after[0][capacity]);
                    }
                }
            }
            after = current;
        }
        return after[1][2];
    }
};