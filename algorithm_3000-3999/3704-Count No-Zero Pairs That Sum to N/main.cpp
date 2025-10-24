class Solution {
public:
    long long countNoZeroPairs(long long n) {
        vector<int> digits;
        for (; n; n /= 10) {
            digits.push_back(n % 10);
        }

        long long cache[digits.size()][2][2][2];
        fill(&cache[0][0][0][0], &cache[0][0][0][0] + sizeof(cache) / sizeof(long long), -1);

        std::function<long long(int, int, bool, bool)> dfs = [&](int idx, int carry, bool end1, bool end2) {
            if (idx == digits.size()) {
                return (carry == 0) ? 1LL : 0LL;
            }

            long long& ret = cache[idx][carry][end1][end2];
            if (ret >= 0) {
                return ret;
            }

            ret = 0;
            int dBgn1 = (idx == 0 ? 1 : 0);
            int dBgn2 = (idx == 0 ? 1 : 0);
            int dEnd1 = (end1 ? 0 : 9);
            int dEnd2 = (end2 ? 0 : 9);
            for (int d1 = dBgn1; d1 <= dEnd1; ++d1) {
                for (int d2 = dBgn2; d2 <= dEnd2; ++d2) {
                    int sum = d1 + d2 + carry;
                    if (sum % 10 != digits[idx]) { continue; }
                    ret += dfs(idx + 1, sum / 10, end1 || (d1 == 0), end2 || (d2 == 0));
                }
            }

            return ret;
        };

        return dfs(0, 0, false, false);
    }
};
