class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        while (i < n && isspace(s[i])) {
            ++i;
        }

        int indicator = 1;
        if (i < n) {
            if (s[i] == '+') {
                ++i;
            }
            else if (s[i] == '-') {
                indicator = -1;
                ++i;
            }
        }

        long num = 0;
        for (; i < n && isdigit(s[i]); ++i) {
            num = num * 10 + s[i] - '0';
            if (num * indicator > INT_MAX) {
                return INT_MAX;
            }
            else if (num * indicator < INT_MIN) {
                return INT_MIN;
            }
        }

        return num * indicator;
    }
};
