class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit = 0;
        int n = prices.size();
        vector<int> temp1(2, 0), temp2(2, 0);
        temp1[0] = 0;
        temp2[1] = 0;
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    profit = max(-prices[index] + temp1[0], 0 + temp1[1]);
                } else {
                    profit = max(prices[index] + temp1[1], 0 + temp1[0]);
                }
                temp2[buy] = profit;
            }
            temp1 = temp2;
        }
        return temp1[1];
    }
};