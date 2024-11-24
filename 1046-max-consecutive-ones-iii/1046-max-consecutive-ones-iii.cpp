class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
          
          int low = 0 , high = 0,zeros = 0,maxLen = 0, len = 0;

        while(high < nums.size()){
             
             if(nums[high] == 0){
                   zeros++;
             }
            if(zeros > k ){
                  if(nums[low] == 0)
                     zeros--;
                     low++;
                  
            }
            if(zeros <= k){
                len = (high - low + 1);
                 maxLen = max(maxLen,len);
            }
            high++;
        }
        return maxLen;
    }
};