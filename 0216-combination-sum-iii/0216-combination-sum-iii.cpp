class Solution {
public:
    void Solve(int index, int k, int sum, vector<int>& current,
               vector<vector<int>>& ans) {

        if (current.size() == k && sum == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = index; i <= 9; i++) {
            if (sum - i < 0)
                break;
            current.push_back(i);
            Solve(i + 1, k, sum - i, current, ans);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> ans;
        if (n < k)
            return ans;
        vector<int> current;
        Solve(1, k, n, current, ans);
        return ans;
    }
};