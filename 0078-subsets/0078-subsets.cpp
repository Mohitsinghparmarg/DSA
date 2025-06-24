class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> subs(1 << nums.size());

        for (int i = 0; i < 1 << nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if ((i >> j) & 1) {
                    subs[i].push_back(nums[j]);
                }
            }
        }
        return subs;
    }
};