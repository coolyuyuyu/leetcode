class Solution {
public:
    int memo[105][2][10];

    int M = 1e9 + 7;

    int dfs(int len, bool samePrefix, char pre, const string& num) {
        if (len == 0) {
            return 1;
        }

        int& ret = memo[len][samePrefix ? 1 : 0][pre - '0'];
        if (0 <= ret) {
            return ret;
        }

        ret = 0;
        if (samePrefix) {
            char cur = num[num.size() - len];

            if ((pre + 1) < cur) {
                ret = (ret + dfs(len - 1, false, pre + 1, num)) % M;
            }
            else if ((pre + 1) == cur) {
                ret = (ret + dfs(len - 1, true, pre + 1, num)) % M;
            }

            if ((pre - 1) >= '0' && (pre - 1) < cur) {
                ret = (ret + dfs(len - 1, false, pre - 1, num)) % M;
            }
            else if ((pre - 1) == cur) {
                ret = (ret + dfs(len - 1, true, pre - 1, num)) % M;
            }
        }
        else {
            if ((pre + 1) <= '9') {
                ret = (ret + dfs(len - 1, false, pre + 1, num)) % M;
            }
            if ((pre - 1) >= '0') {
                ret = (ret + dfs(len - 1, false, pre - 1, num)) % M;
            }
        }

        return ret;
    }

    int helper(const string& num) {
        memset(memo, -1, sizeof(memo));

        int n = num.size();

        int ret = 0;
        for (int len = 1; len < n; ++len) {
            for (char d = '1'; d <= '9'; ++d) {
                ret = (ret + dfs(len - 1, false, d, num)) % M;
            }
        }

        for (char d = '1'; d < num[0]; ++d) {
            ret = (ret + dfs(n - 1, false, d, num)) % M;
        }
        ret = (ret + dfs(n - 1, true, num[0], num)) % M;

        return ret;
    }

    bool checkStepping(const string& num) {
        for (int i = 1; i < num.size(); ++i) {
            if (abs(num[i] - num[i - 1]) != 1) {
                return false;
            }
        }

        return true;
    }

    int countSteppingNumbers(string low, string high) {
        int ret = 0;
        ret = (ret + helper(high)) % M;
        ret = (ret - helper(low) + M) % M;
        ret = (ret + (checkStepping(low) ? 1 : 0)) % M;
        return ret;
    }
};
