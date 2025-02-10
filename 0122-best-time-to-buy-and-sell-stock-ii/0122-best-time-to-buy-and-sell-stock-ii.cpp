class Solution {
public:
  
    int maxProfit(vector<int>& prices) {
           
           int n = prices.size();
           vector<vector<int>> t(n+1 , vector<int>(2 , 0));
           
           t[n][0] = 0;
           t[n][1] = 0;
          for(int index = n-1; index >= 0; index--){
              for(int buy = 0; buy <= 1; buy++){
                  int profit = 0;
                 if(buy){
                     profit = max(-prices[index] + t[index+1][0], t[index+1][1]);
                 }
                 else{
                     profit = max(prices[index] + t[index+1][1], t[index+1][0]);
                 }
                t[index][buy] = profit;
              }
          }
        return t[0][1];
    }
};