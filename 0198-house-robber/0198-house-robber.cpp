class Solution {
public:
    int rob(vector<int>& nums) {
          
          int n = nums.size();
          int prev2 = 0;
          int prev1 = nums[0];

          for(int i = 1; i<n; i++){
               
                int pick = nums[i];
                if(i > 1){
                     pick += prev2;
                }
                int notPick = prev1;

              int curr = max(pick,notPick);
              prev2 = prev1;
              prev1 = curr;
          }
        return prev1;
    }
};