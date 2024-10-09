class Solution {
public:

    int FirstPositionIs(vector<int>&nums,int target){
              
             int start = 0;
             int end = nums.size() - 1;
             int FirstPosition = -1;
            while(start <= end){
                   int mid = (start + (end - start)/2);
                 if(nums[mid] == target){
                       FirstPosition = mid;
                       end = mid - 1;
                  }
                 else if(nums[mid] < target){
                         start = mid + 1;
                 }
                else{
                      end = mid - 1;
                }
            }
        return FirstPosition;
    }

    int LastPositionIs(vector<int>&nums,int target){
               
                int start = 0;
                int end   = nums.size() - 1;
                int LastPosition = -1;
             while(start <= end){
                  int mid = (start + (end - start)/2);
                if(nums[mid] == target){
                       LastPosition = mid;
                       start = mid + 1;
                }
               else if(nums[mid] < target){
                       start = mid + 1;
                }
               else{
                       end = mid - 1;
               }
             } 
         return LastPosition;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
          
          int FirstPosition = FirstPositionIs(nums,target);
          int LastPosition  = LastPositionIs(nums,target);
        return {FirstPosition,LastPosition};
        
    }
};