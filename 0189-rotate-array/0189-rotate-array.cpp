class Solution {
public:
    void reverse(vector<int>& nums, int s, int e) {

        while (s < e) {
            swap(nums[s], nums[e]);
            s++;
            e--;
        }
    }

    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        k = k % n;
        if (k > n)
            return;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
};