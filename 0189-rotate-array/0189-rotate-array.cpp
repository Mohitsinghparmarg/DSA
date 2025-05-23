class Solution {
public:

  void reverse(vector<int>&nums,int i,int j){
             
             while(i<j){
                 int temp = nums[i];
                 nums[i] = nums[j];
                 nums[j] = temp;
                 i++;
                 j--;
             }
  }


    void rotate(vector<int>& nums, int k) {
          
            int n = nums.size();
            k = k%n;
           if(k == 0)
                return;
          reverse(nums,0,n-1);
          reverse(nums,0,k-1);
          reverse(nums,k,n-1);
    }
};