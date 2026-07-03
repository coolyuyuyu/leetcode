class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();

        long long len = 0;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            switch (c) {
                case '*':
                    len = std::max(len - 1, 0LL);
                    break;
                case '#':
                    len *= 2;
                    break;
                case '%':
                    break;
                default:
                    len += 1;
                    break;
            }
        }
        if (k >= len) { 
            return '.';
        }

        for (int i = n - 1; i >= 0; --i) {
            char c = s[i];
            switch (c) {
                case '*':
                    len += 1;
                    break;
                case '#':
                    len /= 2;
                    if (k >= len) {
                        k -= len;
                    }
                    break;
                case '%':
                    k = len - k - 1;
                    break;
                default:
                    --len;
                    if (k == len) {
                        return c;
                    }
                    break;
            }
        }

        return '.';
    }
};
