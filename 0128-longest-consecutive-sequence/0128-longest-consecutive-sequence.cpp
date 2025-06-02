class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int ans = 1;
        unordered_set<int> st;
        if(nums.size() == 0)
              return 0;
        for (auto it : nums) {
            st.insert(it);
        }
        for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
                int count = 1;
                int value = it;
                while (st.find(value + 1) != st.end()) {
                    count++;
                    value += 1;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};