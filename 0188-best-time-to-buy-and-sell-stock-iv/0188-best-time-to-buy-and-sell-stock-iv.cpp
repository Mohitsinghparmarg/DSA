class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> after(2 * k + 1, 0);
        vector<int> current(2 * k + 1, 0);

        for (int index = prices.size() - 1; index >= 0; index--) {
            for (int transaction = 2 * k - 1; transaction >= 0; transaction--) {
                if (transaction % 2 == 0) {
                    current[transaction] =
                        max(-prices[index] + after[transaction + 1],
                            0 + after[transaction]);
                } else {
                    current[transaction] =
                        max(prices[index] + after[transaction + 1],
                            0 + after[transaction]);
                }
            }
            after = current;
        }
        return after[0];
    }
};