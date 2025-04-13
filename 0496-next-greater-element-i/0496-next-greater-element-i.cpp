class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> v;
        for (auto num : nums1) {

            bool flag = false;
            int ans = -1;
            for (int i = 0; i < nums2.size(); i++) {

                if (nums2[i] == num) {
                    flag = true;
                }
                if (flag && nums2[i] > num) {
                    ans = nums2[i];
                    break;
                }
            }
            v.push_back(ans);
        }
        return v;
    }
};