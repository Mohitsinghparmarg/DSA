class Solution {
public:

    int n;

    bool IsPalindrome(string s, int index, int i) {
        while (index < i) {
            if (s[index] != s[i]) {
                return false;
            }
            index++;
            i--;
        }
        return true;
    }

    void solve(string& s, int index, vector<string>& current, vector<vector<string>>& result) {

        if (index == n) {
            result.push_back(current);
            return;
        }

        for (int i = index; i < n; i++) {
            if (IsPalindrome(s, index, i)) {
                current.push_back(s.substr(index, i - index + 1));
                solve(s, i + 1, current, result); 
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<vector<string>> result;
        vector<string> current;
        solve(s, 0, current, result);
        return result;
    }
};
