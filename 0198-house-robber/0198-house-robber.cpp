class Solution {
public:
    int Solve(vector<int>& nums, int index, vector<int>& dp) {
        if (index == 0)
            return nums[0];
        if (index < 0)
            return 0;
        if (dp[index] != -1)
            return dp[index];
        int pick = nums[index] + Solve(nums, index - 2, dp);
        int notpick = 0 + Solve(nums, index - 1, dp);
        return dp[index] = max(pick, notpick);
    }
    int rob(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n, -1);
        return Solve(nums, n - 1, dp);
    }
};