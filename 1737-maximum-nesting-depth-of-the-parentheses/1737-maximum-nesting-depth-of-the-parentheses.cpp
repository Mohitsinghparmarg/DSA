class Solution {
public:
    int maxDepth(string s) {

        stack<char> st;
        int maxi = 0;
        for (auto ch : s) {
            if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                st.pop();
            }
            maxi = max(maxi, (int)st.size());
        }
        return maxi;
    }
};