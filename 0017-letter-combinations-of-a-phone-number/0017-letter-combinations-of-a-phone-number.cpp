class Solution {
public:
    void Solve(int index, const string& digits, const vector<string>& phoneMap,
               string& current, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        string letters = phoneMap[digits[index] - '0'];
        for (char ch : letters) {
            current.push_back(ch);
            Solve(index + 1, digits, phoneMap, current, result);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        vector<string> phoneMap = {"",    "",    "abc",  "def", "ghi",
                                   "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> result;
        string current;
        Solve(0, digits, phoneMap, current, result);
        return result;
    }
};
