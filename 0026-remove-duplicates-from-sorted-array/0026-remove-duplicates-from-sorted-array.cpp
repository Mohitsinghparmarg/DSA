class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         set<int>st;
         for(auto it : nums){
              st.insert(it);
         } 
        int i = 0;
        for(auto it : st){
             nums[i] = it;
             i++;
        }
        return i;
    }
};