class Solution {
public:
    int byDFS(vector<int>& nums, int k) {
        int n = nums.size();

        std::sort(nums.begin(), nums.end());

        int ret = INT_MAX;
        vector<bool> visited(n, false);
        std::function<void(int, int, int, int, int)> dfs = [&](int prev, int cnt, int sum, int mn, int mx) {
            if (cnt == n / k) {
                int cur = n;
                for (int i = 0; i < n; ++i) {
                    if (!visited[i]) {
                        cur = i;
                        break;
                    }
                }

                if (cur == n) {
                    ret = std::min(ret, sum + (mx - mn));
                }
                else {
                    visited[cur] = true;
                    dfs(cur, 1, sum + (mx - mn), nums[cur], nums[cur]);
                    visited[cur] = false;
                }
            }
            else {
                int last = -1;
                for (int i = prev + 1; i < n; ++i) {
                    if (visited[i]) { continue; }
                    if (nums[i] == nums[prev]) { continue; }
                    if (nums[i] == last) { continue; }

                    visited[i] = true;
                    dfs(i, cnt + 1, sum, mn, nums[i]);
                    visited[i] = false;
                    last = nums[i];
                }
            }
        };

        visited[0] = true;
        dfs(0, 1, 0, nums[0], nums[0]);

        return ret == INT_MAX ? -1 : ret;
    }

    int byDP(vector<int>& nums, int k) {
        int n = nums.size();

        std::function<bool(int, int&)> checkDup = [&](int state, int& value) {
            vector<int> subsetNums;
            for (int i = 0; i < n; ++i) {
                if ((state >> i) & 1) {
                    subsetNums.push_back(nums[i]);
                }
            }
            sort(subsetNums.begin(),subsetNums.end());
            for (int i = 1; i < subsetNums.size(); ++i) {
                if (subsetNums[i - 1] == subsetNums[i]) {
                    return true;
                }
            }
            value = subsetNums.back() - subsetNums.front();
            return false;
        };

        // <state, value>
        // state: the binary representation of 1 subset, which is containing (n/k) 1-bits
        // value: incompatibility of the state
        vector<pair<int, int>> pairs;
        // Gosper's hack: Iterate all the n-bit state where there are (n/k)) 1-bits.
        for (int state = (1 << (n / k)) - 1; state < (1 << n);) {
            int value;
            if (!checkDup(state, value)) {
                pairs.emplace_back(state, value);
            }

            int c = state & - state;
            int r = state + c;
            state = (((r ^ state) >> 2) / c) | r;
        }

        // result: binary representation of used nums
        vector<int> results;
        for (int state = 0; state < (1 << n); ++state) {
            if (__builtin_popcount(state) % (n / k) == 0) {
                results.push_back(state);
            }
        }
        std::reverse(results.begin(), results.end());

        // dp[i][result]: considering states[0:i], the incompatibility of result
        int dp[1 << n];
        std::fill(dp, dp + (1 << n), INT_MAX / 2);
        dp[0] = 0;
        for (const auto& [state, value] : pairs) {
            for (int result : results) {
                if ((result & state) != state) {
                    continue;
                }
                dp[result] = std::min(dp[result], dp[result - state] + value);
            }
        }

        int ret = dp[(1 << n) - 1];
        if (ret == INT_MAX / 2) {
            ret = -1;
        }
        return ret;
    }

    int minimumIncompatibility(vector<int>& nums, int k) {
        //return byDFS(nums, k);
        return byDP(nums, k);
    }
};
