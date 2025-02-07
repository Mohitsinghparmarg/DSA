class Solution {
public:
  
  int Solve(vector<int>& nums){

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



    int rob(vector<int>& nums) {
           
           int n = nums.size();
           vector<int>temp1,temp2;
           if(n == 1)
               return nums[0];
           for(int i = 0; i<n; i++){
               if(i != 0){
                     temp1.push_back(nums[i]);
               }
               if(i != n-1){
                   temp2.push_back(nums[i]);
               }
           }
        return max(Solve(temp1),Solve(temp2));
    }
};