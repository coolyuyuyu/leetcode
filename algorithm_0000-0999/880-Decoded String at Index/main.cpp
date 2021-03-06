class Solution {
public:
    string decodeAtIndex(string S, int K) {
        size_t len = 0;
        for (char c : S) {
            if (isdigit(c)) {
                len *= (c - '0');
            }
            else {
                ++len;
            }
        }

        for (size_t i = S.size(); 0 < i--;) {
            if (isdigit(S[i])) {
                len /= (S[i] - '0');
                K %= len;
            }
            else {
                if (K == 0 || K == len) {
                    return string(1, S[i]);
                }
                --len;
            }
        }

        return "";
    }
};