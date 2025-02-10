class Solution {
public:

   int Solve(vector<int>& prices , int index , int buy , int n , vector<vector<int>> &t){
              
          if(index == n){
              return 0;
            }
          if(t[index][buy] != -1){
                return t[index][buy];
          }

         int profit = 0;

          if(buy){
                profit = max( -prices[index] + Solve(prices , index + 1 , 0 , n , t) ,
                    0 + Solve(prices , index + 1 , 1 , n , t));
          }
          else{
                 profit = max(prices[index] + Solve(prices , index + 1 , 1 , n , t) ,
                               0 + Solve(prices , index + 1 , 0 , n , t));
              }

        return t[index][buy] = profit;
   }
    
    int maxProfit(vector<int>& prices) {
           
           int n = prices.size();
           vector<vector<int>> t(n , vector<int>(2 , -1));
        return Solve(prices , 0 , 1 , n , t);
    }
};