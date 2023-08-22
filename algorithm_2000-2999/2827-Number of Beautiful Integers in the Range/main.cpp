class Solution {
public:
    int memo[11][2][20][21];

    int dfs(int len, bool samePrefix, int rem, int diff, const string& num, int k) {
        if (len < abs(diff)) {
            return 0;
        }

        if (len == 0) {
            return (rem == 0 && diff == 0 ? 1 : 0);
        }

        int& ret = memo[len][samePrefix ? 1 : 0][rem][diff + 10];
        if (0 <= ret) {
            return ret;
        }

        ret = 0;
        if (samePrefix) {
            int cur = num[num.size() - len] - '0';
            for (int d = 0; d < cur; ++d) {
                ret += dfs(len - 1, false, (rem * 10 + d) % k, diff + (d % 2 == 0) * 2 - 1, num, k);
            }
            ret += dfs(len - 1, true, (rem * 10 + cur) % k, diff + (cur % 2 == 0) * 2 - 1, num, k);
        }
        else {
            for (int d = 0; d <= 9; ++d) {
                ret += dfs(len - 1, false, (rem * 10 + d) % k, diff + (d % 2 == 0) * 2 - 1, num, k);
            }
        }

        return ret;
    }

    int helper(const string& num, int k) {
        memset(memo, -1, sizeof(memo));

        int n = num.size();
        int cur = num[0] - '0';

        int ret = 0;
        for (int len = 2; len < n; len += 2) {
            for (int d = 1; d <= 9; ++d) {
                ret += dfs(len - 1, false, d % k, (d % 2 == 0) * 2 - 1, num, k);
            }
        }

        for (int d = 1; d < cur; ++d) {
            ret += dfs(n - 1, false, d % k, (d % 2 == 0) * 2 - 1, num, k);
        }
        ret += dfs(n - 1, true, cur % k, (cur % 2 == 0) * 2 - 1, num, k);

        return ret;
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        return helper(std::to_string(high), k) - helper(std::to_string(low - 1), k);
    }
};
