class Solution {
public:
    string reverseWords(string s) {

        stringstream ss(s);
        string token = "";
        string result = "";
        while (ss >> token) {
            result = token + " " + result;
        }
        return result.substr(0, result.size() - 1);
    }
};