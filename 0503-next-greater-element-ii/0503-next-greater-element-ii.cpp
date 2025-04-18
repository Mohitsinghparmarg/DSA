class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            bool found = false;
            for (int j = 1; j < n; j++) {
                int k = (i + j) % n;
                if (nums[k] > nums[i]) {
                    ans.push_back(nums[k]);
                    found = true;
                    break;
                }
            }
            if (!found) {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};
