class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> v(n);
        k = k % n;
        for (int i = 0; i < k; i++) {
            v[i] = nums[n - k + i];
        }
        for (int i = k; i < n; i++) {
            v[i] = nums[i - k];
        }
        for (int i = 0; i < n; i++) {
            nums[i] = v[i];
        }
    }
};