class Solution {
public:
    int myAtoi(string s) {

        int n = s.size();
        int i = 0;
        int sign = 1;
        long ans = 0;
        while (i < n && s[i] == ' ') {
            i++;
        }
        if (i == n) {
            return 0;
        }
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');
            if (sign * ans < INT_MIN) {
                return INT_MIN;
            }
            if (sign * ans > INT_MAX) {
                return INT_MAX;
            }
            i++;
        }
        return sign * ans;
    }
};