class Solution {
public:
    int countPermutations(vector<int>& complexity) {

        int n = complexity.size();
        long long ans = 1;
        for (int i = 1; i < n; i++) {
            if (complexity[0] >= complexity[i])
                return 0;
            ans = (ans * i);
            ans %= (int)(1e9) + 7;
        }
        return ans;
    }
};