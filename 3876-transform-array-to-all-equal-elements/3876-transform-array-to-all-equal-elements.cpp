class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {

        int n = nums.size();
        int count = 0;
        vector<int> temp = nums;
        for (int i = 0; i < n - 1; i++) {
            if (temp[i] != 1) {
                temp[i] *= -1;
                temp[i + 1] *= -1;
                count++;
            }
        }
        if (count <= k && temp[n - 1] == 1)
            return true;
        count = 0;
        temp = nums;
        for (int i = 0; i < n - 1; i++) {
            if (temp[i] != -1) {
                temp[i] *= -1;
                temp[i + 1] *= -1;
                count++;
            }
        }
        if (count <= k && temp[n - 1] == -1)
            return true;
        return false;
    }
};