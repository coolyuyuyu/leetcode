class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();

        string ret = s;
        for (int i = 0; i < ((b & 1) ? 10 : 1); ++i) {
            for (int j = 0; j < 10; ++j) {
                string t = s;
                for (int k = 0; k < n; k += 2) {
                    t[k] = '0' + (t[k] - '0' + i * a) % 10;
                }
                for (int k = 1; k < n; k += 2) {
                    t[k] = '0' + (t[k] - '0' + j * a) % 10;
                }

                for (int k = 0; k < n / std::gcd(n, b); ++k) {
                    std::rotate(t.begin(), t.begin() + b, t.end());
                    ret = std::min(ret, t);
                }
            }
        }

        return ret;
    }
};
