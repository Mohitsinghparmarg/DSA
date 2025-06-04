class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
                 
                 int n = nums.size();
                unordered_map<int,int>mpp;
                vector<int>v;
              for(auto it : nums){
                    mpp[it]++;
              }
              for(auto it : mpp){
                   if(it.second > n/3)
                          v.push_back(it.first);
              }
            return v;
    }
};