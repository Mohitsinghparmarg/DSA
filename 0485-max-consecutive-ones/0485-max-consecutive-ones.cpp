class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
             
             int n = nums.size();
             int i = 0;
             int j = 0;
             int maxi = 0;
            while(j < n){
                  if(nums[j] == 0){
                       j++;
                       i = j;
                  }
                  else{
                       maxi = max((j - i + 1), maxi);
                       j++;
                  }
            }
        return maxi;
    }
};