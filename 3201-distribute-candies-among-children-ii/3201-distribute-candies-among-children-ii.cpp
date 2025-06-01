class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long total = 0;
        for (int a = max(0, n - 2 * limit); a <= min(limit, n); a++) {
            int b = min(limit, n - a) - max(0, n - a - limit) + 1;
            total += max(0, b);
        }
        return total;
    }
};