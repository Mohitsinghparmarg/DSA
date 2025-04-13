class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> mpp;
        vector<int> ans;
        stack<int> st;
        for (auto num : nums2) {
            while (!st.empty() && num > st.top()) {
                mpp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        while (!st.empty()) {
            mpp[st.top()] = -1;
            st.pop();
        }
        for (auto num : nums1) {
            ans.push_back(mpp[num]);
        }
        return ans;
    }
};