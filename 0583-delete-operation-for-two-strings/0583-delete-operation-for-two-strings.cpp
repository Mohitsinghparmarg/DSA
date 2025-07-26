class Solution {
public:
    int Solve(int i, int j, string& s, string& s2, vector<vector<int>>& dp) {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == s2[j])
            return dp[i][j] = 1 + Solve(i - 1, j - 1, s, s2, dp);
        else
            return dp[i][j] = max(Solve(i - 1, j, s, s2, dp),
                                  Solve(i, j - 1, s, s2, dp));
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return n + m - 2 * Solve(n - 1, m - 1, word1, word2, dp);
    }
};