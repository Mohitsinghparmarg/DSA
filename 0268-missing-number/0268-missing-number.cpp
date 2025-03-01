class Solution {
public:
    int missingNumber(vector<int>& nums) {
          
          int n = nums.size();
          int j = 0;
          sort(nums.begin(),nums.end());

          for(int i = 0; i<n; i++){
              if(nums[i] != j){
                    break;
              }
              j++;
          }
        return j;
    }
};