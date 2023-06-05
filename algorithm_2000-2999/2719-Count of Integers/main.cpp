class Solution {
public:
    int M = 1e9 + 7;

    int countLE(const std::string& num, int maxDSum) {
        int n = num.size();
        int cache[n][maxDSum + 1][2];
        std::memset(cache, -1, sizeof(cache));
        std::function<int(int, int, bool)> dfs = [&](int idx, int dsum, bool samePrefix) {
            if (maxDSum < dsum) {
                return 0;
            }
            if (n <= idx) {
                return 1;
            }

            int& ret = cache[idx][dsum][samePrefix ? 1 : 0];
            if (0 <= ret) {
                return ret;
            }

            ret = 0;
            if (samePrefix) {
                for (int i = 0; i < (num[idx] - '0'); ++i) {
                    ret += dfs(idx + 1, dsum + i, false);
                    ret %= M;
                }
                ret += dfs(idx + 1, dsum + (num[idx] - '0'), true);
                ret %= M;
            }
            else {
                for (int i = 0; i < 10; ++i) {
                    ret += dfs(idx + 1, dsum + i, false);
                    ret %= M;
                }
            }

            return ret;
        };

        return dfs(0, 0, true);
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        //return (countLE(num2, max_sum) - countLE(num2, min_sum - 1)) - (countLE(num1 - 1, max_sum) - countLE(num1 - 1, min_sum - 1));

        int ret = (countLE(num2, max_sum) - countLE(num2, min_sum - 1)) - (countLE(num1, max_sum) - countLE(num1, min_sum - 1));

        int dSum = 0;
        for (char c : num1) {
            dSum += (c - '0');
        }
        if (min_sum <= dSum && dSum <= max_sum) {
            ret += 1;
        }

        return ret;
    }
};

// count(num1, num2, min_sum, max_sum):
//     = countLE(num2, min_sum, max_sum) - countLE(num1 - 1, min_sum, max_sum)
//     = (countLE(num2, max_sum) - countLE(num2, min_sum - 1)) - (countLE(num1 - 1, max_sum) - countLE(num1 - 1, min_sum - 1))
