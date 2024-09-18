//  Company Tags : Google, Microsoft, Amazon, Ebay, Meta

// Greedy Approach...



class Solution {
  public:
    bool canJump(vector<int>& nums) {
              
              int n = nums.size();
              int MaximumKahaanTkBhai = 0;
            for(int i = 0; i<n; i++){
                   if(i > MaximumKahaanTkBhai)
                       {
                           return false;
                       }
                    MaximumKahaanTkBhai = max(MaximumKahaanTkBhai, i + nums[i]);
            }
        return true;
    }
};  




// Bottom UP Approach...


/* 

class Solution {
  public:
    bool canJump(vector<int>& nums) {
            
            int n = nums.size();
          vector<bool>t(n,false);

          // t[i] == true , mtlb tumhaaraa bhai i tk pahunch sktaa h
          // t[i] == false , nhi pahunch skte bhai tum , so sad for you bhai...

         t[0] = true; // koi naa abhi tumhaaraa bhai 1st index pr khdaa h

         for(int i = 1; i<n; i++){
              for(int j = i-1; j>=0; j--){
                   if(t[j] == true && j + nums[j] >= i){
                          t[i] = true;
                          break;
                   }
              }
         }
        return t[n-1];
    }
};



*/



// Recursion + Memoization

/*
class Solution {
  public:
    int t[10001];
    bool solve(vector<int>&nums,int n,int index){
           
            if(index == n-1)
                return true;
            if(t[index] != -1)
                  return t[index];
          for(int i = 1; i<=nums[index]; i++){
                 if(solve(nums,n,index+1) == true)
                      {
                         return t[index] =  true;
                      }
          }
        return t[index] = false;
   }

    bool canJump(vector<int>& nums) {
          memset(t,-1,sizeof(t));
           return solve(nums,nums.size(),0);
    }
};

*/


// Recursion
/* 
class Solution {
  public:
    bool solve(vector<int>&nums,int n,int index){
           
            if(index == n-1)
                return true;
          for(int i = 1; i<=nums[index]; i++){
                 if(solve(nums,n,index+1) == true)
                      {
                         return true;
                      }
          }
        return false;
   }

    bool canJump(vector<int>& nums) {
          
           return solve(nums,nums.size(),0);
    }
};

*/