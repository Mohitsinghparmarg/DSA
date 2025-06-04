class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();
        int count1 = 0;
        int element1 = INT_MIN;
        int count2 = 0;
        int element2 = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (count1 == 0 && element2 != nums[i]) {
                count1++;
                element1 = nums[i];
            } else if (count2 == 0 && element1 != nums[i]) {
                count2++;
                element2 = nums[i];
            } else if (element1 == nums[i]) {
                count1++;
            } else if (element2 == nums[i]) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        vector<int> v;
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < n; i++) {
            if (element1 == nums[i]) {
                count1++;
            } else if (element2 == nums[i]) {
                count2++;
            }
        }
        int mini = int(n / 3) + 1;
        if (count1 >= mini)
            v.push_back(element1);
        if (count2 >= mini)
            v.push_back(element2);
        return v;
    }
};