class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 1;
        int count = 0;
        int prev = INT_MIN;
        if (n == 0) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] - 1 == prev) {
                count++;
                prev = nums[i];
            } else if (nums[i] != prev) {
                count = 1;
                prev = nums[i];
            }
            ans = max(ans, count);
        }
        return ans;
    }
};