class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int element;
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                element = nums[i];
                count++;
            } else if (element == nums[i]) {
                count++;
            } else {
                count--;
            }
        }
        count = 0;
        for (auto it : nums) {
            if (it == element) {
                count++;
                if (count > n / 2) {
                    break;
                }
            }
        }
        return element;
    }
};