class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
          
          int start = 0;
          int end = nums.size() - 1;
          int FirstPosition = -1;
          vector<int>v;

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
        v.push_back(FirstPosition);
             
         start = 0;
         end = nums.size() -1 ;
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
        v.push_back(LastPosition);
        return v;
        
    }
};