class Solution {
public:
    int Solve(int i, int j, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) {
            return 1;
        }
        if (i < 0 || j < 0) {
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = Solve(i - 1, j, dp) + Solve(i, j - 1, dp);
    }
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return Solve(m - 1, n - 1, dp);
    }
};