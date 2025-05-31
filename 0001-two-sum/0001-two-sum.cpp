class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            int actual_number = nums[i];
            int search_value = target - nums[i];
            if (mpp.find(search_value) != mpp.end()) {
                return {mpp[search_value], i};
            }
            mpp[actual_number] = i;
        }
        return {-1, -1};
    }
};