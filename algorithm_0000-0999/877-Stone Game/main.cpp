class Solution {
public:
    // Almost same as 486. Predict the Winner

    bool recursion(const vector<int>& nums) {
        int n = nums.size();

        vector<int> presum(n);
        std::partial_sum(nums.begin(), nums.end(), presum.begin());
        std::function<int(int, int)> sum = [&](int lo, int hi) {
            return presum[hi] - (0 < lo ? presum[lo - 1] : 0);
        };

        std::function<int(int, int)> f = [&](int lft, int rht) {
            if (lft == rht) {
                return nums[lft];
            }

            // f(lft, rht) = std::max(
            //     nums[lft] + sum(lft + 1, rht) - f(lft + 1, rht),
            //     nums[rht] + sum(lft, rht - 1) - f(lft, rht - 1),
            // );

            return sum(lft, rht) - std::min(f(lft + 1, rht), f(lft, rht -1));
        };

        return sum(0, n - 1) <= (f(0, n - 1) * 2);
    }

    bool recursion_memo(const vector<int>& nums) {
        int n = nums.size();

        vector<int> presum(n);
        std::partial_sum(nums.begin(), nums.end(), presum.begin());
        std::function<int(int, int)> sum = [&](int lo, int hi) {
            return presum[hi] - (0 < lo ? presum[lo - 1] : 0);
        };

        int cache[n][n];
        for (int lft = 0; lft < n; ++lft) {
            for (int rht = lft; rht < n; ++rht) {
                cache[lft][rht] = -1;
            }
        }

        std::function<int(int, int)> f = [&](int lft, int rht) {
            int& ret = cache[lft][rht];
            if (0 <= ret) {
                return ret;
            }

            if (lft == rht) {
                return ret = nums[lft];
            }

            return ret = sum(lft, rht) - std::min(f(lft + 1, rht), f(lft, rht -1));
        };

        return sum(0, n - 1) <= (f(0, n - 1) * 2);
    }

    bool btmup_dp(const vector<int>& nums) {
        int n = nums.size();

        vector<int> presum(n);
        std::partial_sum(nums.begin(), nums.end(), presum.begin());
        std::function<int(int, int)> sum = [&](int lo, int hi) {
            return presum[hi] - (0 < lo ? presum[lo - 1] : 0);
        };

        // dp[i][j]: the maximum score the player can get from nums[i:j]
        int dp[n][n];
        for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }
        for (int len = 2; len <= n; ++len) {
            for (int lft = 0, rht = lft + len - 1; rht < n; ++lft, ++rht) {
                dp[lft][rht] = sum(lft, rht) - std::min(dp[lft + 1][rht], dp[lft][rht -1]);
            }
        }

        return sum(0, n - 1) <= (dp[0][n - 1] * 2);
    }

    bool math(const vector<int>& nums) {
        return true;
    }

    bool stoneGame(vector<int>& piles) {
        //return recursion(piles);
        //return recursion_memo(piles);
        //return btmup_dp(piles);
        return math(piles);
    }
};
