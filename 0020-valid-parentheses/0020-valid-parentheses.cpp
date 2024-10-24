class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mpp = {{')', '('}, {']', '['}, {'}', '{'}};

        for (auto& x : s) {
            if (mpp.find(x) == mpp.end()) {
                st.push(x);
            } else if (!st.empty() && mpp[x] == st.top()) {
                st.pop();
            } else {
                return false;
            }
        }

        return st.empty();        
    }
};