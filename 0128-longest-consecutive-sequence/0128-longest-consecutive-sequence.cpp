class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
             
             if(nums.size() == 0)
                   return 0;
             int longest = 1;
             unordered_set<int>st;
            for(auto it : nums){
                 st.insert(it);
            }
            for(auto it : st){
                    
                 if(st.find(it-1) == st.end()){
                    int count = 1;
                     int value = it;
                    while(st.find(value+1) != st.end()){
                          count++;
                          value = value+1;
                    }
                    longest = max(longest,count);
                 }
                
            }
        return longest;
    }
};