class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size() / 2;

        vector<vector<int>> stateGroups(n + 1);
        stateGroups[0].push_back(0);
        for (int i = 1; i <= n; ++i) {
            // gosper' hack
            int state = (1 << (2 * i)) - 1;
            while (state < (1 << (2 * n))) {
                stateGroups[i].push_back(state);

                int c = state & - state;
                int r = state + c;
                state = (((r ^ state) >> 2) / c) | r;
            }
        }

        vector<vector<int>> g(2 * n, vector<int>(2 * n));
        for (int i = 0; i < (2 * n); ++i) {
            for (int j = i + 1; j < (2 * n); ++j) {
                g[i][j] = std::gcd(nums[i], nums[j]);
            }
        }

        std::function<pair<int,int>(int)> findIndexPair = [n](int state) {
            int idx1 = -1, idx2;
            for (int i = 0; i < (2 * n); ++i) {
                if (1 << i & state) {
                    if (idx1 == -1) {
                        idx1 = i;
                    }
                    else {
                        idx2 = i;
                        break;
                    }
                }
            }

            return make_pair(idx1, idx2);
        };

        vector<int> dp(1 << (2 * n), 0);
        for (int i = 1; i <= n; ++i) {
            for (int state : stateGroups[i]) {
                // 1. iterate substate from state.
                if (i == 1) {
                    auto [idx1, idx2] = findIndexPair(state);
                    dp[state] = std::max(dp[state], g[idx1][idx2]);
                }
                else {
                    for (int substate = state; substate > 0; substate = (substate - 1) & state) {
                        if (__builtin_popcount(substate) != 2 * (i - 1)) {
                            continue;
                        }

                        auto [idx1, idx2] = findIndexPair(state - substate);
                        dp[state] = std::max(dp[state], dp[substate] + i * g[idx1][idx2]);
                    }
                }

                /*
                // 2. iterate all possible substate and exclude non-subset.
                for (int substate : stateGroups[i - 1]) {
                    if ((state & substate) != substate) {
                        continue;
                    }

                    auto [idx1, idx2] = findIndexPair(state - substate);
                    dp[state] = std::max(dp[state], dp[substate] + i * g[idx1][idx2]);
                }
                */
            }
        }

        return dp[(1 << (2 * n)) - 1];
    }
};

// for (int i = 1; i <= n; ++i)
//     dp[state A of 2*i 1-bits] = max({dp[substate B of 2*(i-1) 1-bits] + gcd(nums[index1], nums[index2])})
//     substate B must be a subset of state A

