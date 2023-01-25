class Solution {
public:
    // dfs, Time: O(n^2)
    vector<vector<int>> computeLens(const vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> lens(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            vector<int> cnts(1001, 0);
            int len = 0;
            for (int j = i; j < n; ++j) {
                ++cnts[nums[j]];
                if (2 == cnts[nums[j]]) {
                    len += 2;
                }
                else if (2 < cnts[nums[j]]) {
                    len += 1;
                }
                lens[i][j] = len;
            }
        }

        return lens;
    }

    int dfs(const vector<vector<int>>& lens, int start, int k, vector<int>& cache) {
        if (lens.size() <= start) {
            return 0;
        }
        if (0 < cache[start]) {
            return cache[start];
        }

        int cost = INT_MAX;
        for (int i = start; i < lens.size(); ++i) {
            cost = std::min(cost, lens[start][i] + k + dfs(lens, i + 1, k, cache));
        }

        return cache[start] = cost;
    }

    int dfs(const vector<int>& nums, int k) {
        vector<vector<int>> lens = computeLens(nums);
        vector<int> cache(nums.size(), 0);
        return dfs(lens, 0, k, cache);
    }

    // dynamic programming, Time: O(n^2)
    int dp(const vector<int>& nums, int k) {
        int n = nums.size();

        // costs[i]: the minimum possible cost of a split of nums[0:i]
        vector<int> costs(n, INT_MAX);
        for (int i = 0; i < n; ++i) {
            vector<int> cnts(n + 1, 0);
            int len = 0;
            for (int j = i; 0 <= j; --j) {
                ++cnts[nums[j]];
                if (2 == cnts[nums[j]]) {
                    len += 2;
                }
                else if (2 < cnts[nums[j]]) {
                    len += 1;
                }

                if (0 < j) {
                    costs[i] = std::min(costs[i], costs[j - 1] + len + k);
                }
                else {
                    costs[i] = std::min(costs[i], len + k);
                }
            }
        }

        return costs[n - 1];
    }

    int minCost(vector<int>& nums, int k) {
        //return dfs(nums, k);
        return dp(nums, k);
    }
};
