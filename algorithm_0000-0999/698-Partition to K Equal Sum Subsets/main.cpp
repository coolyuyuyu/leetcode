class Solution {
public:
    bool dfs(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int subsum = sum / k;
        if (subsum * k != sum) {
            return false;
        }

        std::sort(nums.begin(), nums.end()); // optimization 1: to avoid duplicate branch
        std::reverse(nums.begin(), nums.end()); // optimization 2: sum is getting exceed earlier

        bool visited[n];
        std::fill(visited, visited + n, false);
        std::function<bool(int, int, int)> f = [&](int cur, int group, int sum) {
            if (group == k) { return true; }
            else if (sum > subsum) { return false; }
            else if (sum == subsum) { return f(0, group + 1, 0); }

            for (int i = cur, last = -1; i < n; ++i) {
                if (visited[i]) { continue; }
                if (nums[i] == last) { continue; }

                visited[i] = true;
                last = nums[i];
                if (f(i + 1, group, sum + nums[i])) {
                    return true;
                }
                visited[i] = false;
            }

            return false;
        };

        return f(0, 0, 0);
    }

    bool dp(vector<int>& nums, int k) {
        int n = nums.size();
        int m = 1 << n;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int subsum = sum / k;
        if (subsum * k != sum) {
            return false;
        }

        // dp[state]: the sum of subsequence of nums presented in binary representation.
        int dp[m];
        std::fill(dp, dp + m, -1);
        dp[0] = 0;
        for (int state = 0; state < m; ++state) {
            if (dp[state] == -1) { continue; }
            for (int i = 0; i < n; ++i) {
                if (state & (1 << i)) { continue; }
                if (dp[state] + nums[i] > subsum) { continue; }
                dp[state | (1 << i)] = (dp[state] + nums[i]) % subsum;
            }
        }

        return dp[m - 1] == 0;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        //return dfs(nums, k);
        return dp(nums, k);
    }
};
