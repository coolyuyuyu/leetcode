class Solution {
public:
    int topdnDFS(vector<int>& stoneValue) {
        int n = stoneValue.size();

        int presum[n];
        std::partial_sum(stoneValue.begin(), stoneValue.end(), presum);
        std::function<int(int, int)> sum = [&](int lo, int hi) {
            return presum[hi] - (0 < lo ? presum[lo - 1] : 0);
        };

        // dp[i][j]: the maximum score Alice can get from stoneValue[i:j]
        int dp[n][n];
        for (int lft = 0; lft < n; ++lft) {
            for (int rht = lft; rht < n; ++rht) {
                dp[lft][rht] = -1;
            }
        }
        std::function<int(int, int)> f = [&](int lft, int rht) {
            int& ret = dp[lft][rht];
            if (ret >= 0) {
                return ret;
            }

            ret = 0;
            for (int mid = lft, lftSum = 0, rhtSum = sum(lft, rht); mid < rht; ++mid) {
                lftSum += stoneValue[mid], rhtSum -= stoneValue[mid];
                if (lftSum < rhtSum) {
                    ret = std::max(ret, lftSum + f(lft, mid));
                }
                else if (lftSum > rhtSum) {
                    ret = std::max(ret, rhtSum + f(mid + 1, rht));
                }
                else {
                    ret = std::max(ret, lftSum + std::max(f(lft, mid), f(mid + 1, rht)));
                }
            }

            return ret;
        };

        return f(0, n - 1);
    }

    int btmupDP(vector<int>& stoneValue) {
        int n = stoneValue.size();

        int presum[n];
        std::partial_sum(stoneValue.begin(), stoneValue.end(), presum);
        std::function<int(int, int)> sum = [&](int lo, int hi) {
            return presum[hi] - (0 < lo ? presum[lo - 1] : 0);
        };

        // dp[i][j]: the maximum score Alice can get from stoneValue[i:j]
        int dp[n][n];
        for (int lft = 0; lft < n; ++lft) {
            for (int rht = lft; rht < n; ++rht) {
                dp[lft][rht] = 0;
            }
        }
        for (int len = 2; len <= n; ++len) {
            for (int lft = 0, rht = lft + len - 1; rht < n; ++lft, ++rht) {
                for (int mid = lft, lftSum = 0, rhtSum = sum(lft, rht); mid < rht; ++mid) {
                    lftSum += stoneValue[mid], rhtSum -= stoneValue[mid];
                    if (lftSum < rhtSum) {
                        dp[lft][rht] = std::max(dp[lft][rht], lftSum + dp[lft][mid]);
                    }
                    else if (lftSum > rhtSum) {
                        dp[lft][rht] = std::max(dp[lft][rht], rhtSum + dp[mid + 1][rht]);
                    }
                    else {
                        dp[lft][rht] = std::max(dp[lft][rht], lftSum + std::max(dp[lft][mid], dp[mid + 1][rht]));
                    }
                }
            }
        }

        return dp[0][n - 1];
    }

    int stoneGameV(vector<int>& stoneValue) {
        return topdnDFS(stoneValue);
        //return btmupDP(stoneValue);
    }
};
