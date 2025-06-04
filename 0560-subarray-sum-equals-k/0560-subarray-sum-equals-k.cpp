class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        unordered_map<int, int> mpp;
        int prefixSum = 0;
        int count = 0;
        mpp[0] = 1;
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            int removal = prefixSum - k;
            count += mpp[removal];
            mpp[prefixSum] += 1;
        }
        return count;
    }
};