class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> res(n, 1);

        int prefix = 1, suffix = 1;

        for (int i = 1; i < n; i++) {
            prefix *= nums[i - 1];
            res[i] *= prefix;

            suffix *= nums[n - i];
            res[n - i - 1] *= suffix;
        }

        return res;
    }
};