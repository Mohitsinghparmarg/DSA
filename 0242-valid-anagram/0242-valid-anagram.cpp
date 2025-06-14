class Solution {
public:
    bool isAnagram(string s, string t) {

        unordered_map<char, int> mpp;
        if (s.size() != t.size())
            return false;
        for (auto it : s) {
            mpp[it]++;
        }
        for (auto it : t) {
            if (mpp.find(it) == mpp.end() || mpp[it] == 0) {
                return false;
            }
            mpp[it]--;
        }
        return true;
    }
};