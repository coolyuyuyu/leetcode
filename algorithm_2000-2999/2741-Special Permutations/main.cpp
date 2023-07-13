class Solution {
public:
    int specialPerm(vector<int>& nums) {
        int n = nums.size();

        long cache[n + 1][1 << n];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < (1 << n); ++j) {
                cache[i][j] = -1;
            }
        }

        int M = 1e9 + 7;

        std::function<long(int, int)> dfs = [&](int pre, int state) -> long {
            long& ret = cache[pre + 1][state];
            if (0 <= ret) {
                return ret;
            }

            if (__builtin_popcount(state) == n) {
                ret = 1;
                return ret;
            }

            ret = 0;
            for (int cur = 0; cur < n; ++cur) {
                if ((state >> cur) & 1) {
                    continue;
                }

                if (pre < 0 || (nums[cur] % nums[pre] == 0 || nums[pre] % nums[cur] == 0)) {
                    ret += dfs(cur, state + (1 << cur));
                    ret %= M;
                }
            }

            return ret;
        };

        return dfs(-1, 0);
    }
};
