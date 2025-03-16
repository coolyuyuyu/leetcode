class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int m = nums.size(), n = queries.size();

        int elems[n];
        std::function<int(int)> f = [&](int target) {
            bool dp[target + 1];
            std::fill(dp, dp + target + 1, false);
            dp[0] = true;
            for (int i = 0; i < n; ++i) {
                for (int s = target; s >= 0; --s) {
                    if (dp[s] && s + elems[i] <= target) {
                        dp[s + elems[i]] = true;
                    }
                }

                if (dp[target]) {
                    return i + 1;
                }
            }

            return INT_MAX;
        };

        int ret = 0;
        for (int i = 0; i < m; ++i) {
            if (nums[i] == 0) { continue; }
            for (int j = 0; j < n; ++j) {
                int l = queries[j][0], r = queries[j][1], v = queries[j][2];
                if (l <= i && i <= r) {
                    elems[j] = v;
                }
                else {
                    elems[j] = 0;
                }
            }

            int k = f(nums[i]);
            if (k == INT_MAX) {
                return -1;
            }
            ret = std::max(ret, k);
        }

        return ret;
    }
};
