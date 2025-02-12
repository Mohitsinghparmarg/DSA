class Solution {
public:
    int majorityElement(vector<int>& nums) {
         
           int count = 0;
           int element;
         for(int i = 0; i<nums.size(); i++){
             if(count == 0){
                  count = 1;
                  element = nums[i];
             }
            else if(element == nums[i]){
                 count++;
             }
            else{
                 count--;
            }
         }
         count = 0;
        for(int i = 0; i<nums.size(); i++){
             if(element == nums[i]){
                 count++;
             }
        }
        if(count > nums.size()/2){
             return element;
        }
     return -1;
    }
};