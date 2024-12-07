class Solution {
public:
    int findMinimumTime(vector<int>& strength, int K) {
        int n = strength.size();

        int cache[1 << n];
        std::fill(cache, cache + (1 << n), INT_MAX);
        std::function<int(int, int)> dfs = [&](int mask, int x) {
            if (mask == ((1 << n) - 1)) {
                return 0;
            }

            int& ret = cache[mask];
            if (ret < INT_MAX) {
                return ret;
            }

            for (int i = 0; i < n; ++i) {
                if ((mask & (1 << i))) { continue; }
                ret = std::min(ret, (strength[i] + x - 1) / x + dfs(mask | (1 << i), x + K));
            }

            return ret;
        };

        return dfs(0, 1);
    }
};
