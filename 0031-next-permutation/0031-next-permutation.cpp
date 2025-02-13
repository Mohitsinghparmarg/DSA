class Solution {
public:
    void nextPermutation(vector<int>& nums) {
            
            int n = nums.size();

            int DippedIndex = -1;

          for(int i = n-2; i>=0; i--){
               if(nums[i] < nums[i+1]){
                     DippedIndex = i;
                     break;
               }
           }
          if(DippedIndex == -1){
             reverse(nums.begin(),nums.end());
             return;
           }
           
           for(int i = n-1; i>DippedIndex; i--){
                   if(nums[i] > nums[DippedIndex]){
                        swap(nums[i],nums[DippedIndex]);
                        break;
                   }
           }
           reverse(nums.begin() + DippedIndex + 1,nums.end());
    }
};