class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
           
           int count = 0;
           int n = nums.size();
           int sum = 0;
           for(int i = 0; i<n; i++){
                 sum += nums[i];
                 if(nums[i] == 0){
                    count++;
                 }
           }
            target = abs(target);
            if(target > sum || (target + sum)%2 != 0){
                  return 0;
            } 
            sum = (sum + target)/2;
            int t[n+1][sum+1];

            

         for(int i = 0; i<n+1; i++){
             for(int j = 0; j<sum+1; j++){
                 if(i == 0){
                    t[i][j] = 0;
                 }
                 if(j == 0){
                    t[i][j] = 1;
                 }
             }
         }
        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<sum+1; j++){
                 if(nums[i-1] == 0){
                    t[i][j] = t[i-1][j];
                }
                else if(nums[i-1] <= j){
                    t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return pow(2,count)*t[n][sum];
    }
};