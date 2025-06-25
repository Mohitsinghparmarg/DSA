class Solution {
public:
    void Solve(int index, vector<int>& candidates, int target,
               vector<vector<int>>& ans, vector<int>& temp) {
        if (index == candidates.size()) {
            if (target == 0) {
                ans.push_back(temp);
            }
            return;
        }
        if (candidates[index] <= target) {
            temp.push_back(candidates[index]);
            Solve(index, candidates, target - candidates[index], ans, temp);
            temp.pop_back();
        }
        Solve(index + 1, candidates, target, ans, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        Solve(0, candidates, target, ans, temp);
        return ans;
    }
};