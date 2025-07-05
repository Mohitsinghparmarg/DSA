class Solution {
public:
    int findLucky(vector<int>& arr) {

        unordered_map<int, int> mpp;
        int maxi = -1;
        for (auto it : arr) {
            mpp[it]++;
        }
        for (auto it : mpp) {
            if (it.first == it.second) {
                maxi = max(maxi, it.first);
            }
        }
        return maxi;
    }
};