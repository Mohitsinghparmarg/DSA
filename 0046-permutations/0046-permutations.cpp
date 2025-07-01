class Solution {
public:
    void Solve(vector<int>& nums, vector<bool>& used, vector<int>& temp,
               vector<vector<int>>& ans) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                temp.push_back(nums[i]);
                used[i] = true;
                Solve(nums, used, temp, ans);
                used[i] = false;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        Solve(nums, used, temp, ans);
        return ans;
    }
};