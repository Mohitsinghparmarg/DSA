class Solution {
public:
    int Solve(vector<int>& nums, int target, bool flag) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = (low + (high - low) / 2);
            if (nums[mid] == target) {
                ans = mid;
                if (flag)
                    high = mid - 1;
                else
                    low = mid + 1;

            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {

        int FirstOccurrence = Solve(nums, target, true);
        int LastOccurrence = Solve(nums, target, false);
        return {FirstOccurrence, LastOccurrence};
    }
};