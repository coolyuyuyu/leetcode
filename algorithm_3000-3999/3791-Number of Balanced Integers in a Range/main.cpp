class Solution {
public:
    long long countLE(const string& num) {
        int n = num.size();

        int OFFSET = n / 2 * 9;
        long long cache[n][2][OFFSET * 2 + 1];
        std::function<long long(int, bool, int, int)> dfs = [&](int idx, bool tight, int balance, int len) {
            if (std::abs(balance) > (n / 2) * 9) {
                return 0LL;
            }
            if (idx >= len) {
                return (balance == 0 ? 1LL : 0LL);
            }

            long long& ret = cache[idx][tight][balance + OFFSET];
            if (ret >= 0) {
                return ret;
            }
            ret = 0;

            int lo = (idx == 0 ? 1 : 0);
            int hi = (tight ? (num[idx] - '0') : 9);
            for (int d = lo; d <= hi; ++d) {
                ret += dfs(idx + 1, tight && d == hi, balance + ((idx & 1) ? 1 : -1) * d, len);
            }

            return ret;
        };

        long long ret = 0;
        for (int len = 2; len < num.size(); ++len) {
            std::fill(&cache[0][0][0], &cache[0][0][0] + (n * 2 * (OFFSET * 2 + 1)), -1);
            ret += dfs(0, false, 0, len);
        }
        std::fill(&cache[0][0][0], &cache[0][0][0] + (n * 2 * (OFFSET * 2 + 1)), -1);
        ret += dfs(0, true, 0, num.size());

        return ret;
    }

    long long countBalanced(long long low, long long high) {
        return countLE(std::to_string(high)) - countLE(std::to_string(low - 1));
    }
};
