class Solution {
public:
    vector<vector<int>> ans;
    void Solve(vector<int>& nums, int index, vector<int>& temp) {
        if (index == nums.size()) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        Solve(nums, index + 1, temp);
        temp.pop_back();
        Solve(nums, index + 1, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> temp;
        Solve(nums, 0, temp);
        return ans;
    }
};