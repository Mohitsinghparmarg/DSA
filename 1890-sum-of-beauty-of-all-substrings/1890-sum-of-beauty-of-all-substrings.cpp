class Solution {
public:
    int beautySum(string s) {

        int n = s.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mpp;
            for (int j = i; j < n; j++) {
                mpp[s[j]]++;
                int LF = INT_MAX;
                int MF = INT_MIN;
                for (auto it : mpp) {
                    LF = min(LF, it.second);
                    MF = max(MF, it.second);
                }
                sum += MF - LF;
            }
        }
        return sum;
    }
};