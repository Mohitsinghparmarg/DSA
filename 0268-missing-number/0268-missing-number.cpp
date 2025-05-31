class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();
        int missing_number = 0;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < n; i++) {
            if (nums[i] != missing_number) {
                break;
            }
            missing_number++;
        }
        return missing_number;
    }
};