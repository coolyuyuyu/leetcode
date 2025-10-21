class Solution {
public:
    int M = 1e9 + 7;
    int magicalSum(int m, int k, vector<int>& nums) {
        int n = nums.size();

        int combCache[m + 1][m + 1];
        std::memset(combCache, -1, sizeof(combCache));
        std::function<int(int, int)> comb = [&](int n, int r) {
            assert(n >= r);
            if ((n - r) < r) {
                r = n - r;
            }

            if (r == 0) {
                return 1;
            }
            else if (r == 1) {
                return n;
            }

            int& ret = combCache[n][r];
            if (ret < 0) {
                // C(m, n) = C(m-1, n) + C(m-1, n-1)
                ret = (comb(n - 1, r - 1) + comb(n - 1, r)) % M;
            }

            return ret;
        };

        int powerCache[n][m + 1];
        for (int i = 0; i < n; ++i) {
            powerCache[i][0] = 1;
            for (int j = 1; j <= m; ++j) {
                powerCache[i][j] = 1L * powerCache[i][j - 1] * nums[i] % M;
            }
        }
        std::function<int(int, int)> power = [&](int i, int j) {
            return powerCache[i][j];
        };

        int resultCache[m + 1][k + 1][n + 1][m + 1];
        std::memset(resultCache, -1, sizeof(resultCache));
        std::function<int(int, int, int, int)> dfs = [&](int m, int k, int i, int carry) {
            if (m < 0) { return 0; }
            else if (k < 0) { return 0; }
            else if (m + __builtin_popcount(carry) < k) { return 0; }
            else if (m == 0) { return (k == __builtin_popcount(carry) ? 1 : 0); }
            else if (i >= n) { return 0; }

            int& ret = resultCache[m][k][i][carry];
            if (ret >= 0) {
                return ret;
            }

            ret = 0;
            for (int cnt = 0; cnt <= m; ++cnt) {
                int ways = 1L * comb(m, cnt) * power(i, cnt) % M;
                int carryNew = carry + cnt;
                ret += 1L * ways * dfs(m - cnt, k - (carryNew % 2), i + 1, carryNew / 2) % M;
                ret %= M;
            }
            return ret;
        };

        return dfs(m, k, 0, 0);
    }
};
