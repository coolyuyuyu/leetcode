class Solution {
public:
    bool dfs(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int subsum = sum / k;
        if (subsum * k != sum) {
            return false;
        }

        int n = nums.size();

        std::sort(nums.rbegin(), nums.rend()); // optimize

        bool visited[n];
        std::fill(visited, visited + n, false);
        std::function<bool(int, int, int)> f = [&](int group, int idx, int sum) {
            if (group == k) {
                return true;
            }
            else if (sum > subsum) {
                return false;
            }
            else if (sum == subsum) {
                return f(group + 1, 0, 0);
            }

            for (int i = idx, last = -1; i < n; ++i) {
                if (visited[i]) { continue; }
                if (nums[i] == last) { continue; } // optimize

                visited[i] = true;
                last = nums[i];
                if (f(group, i + 1, sum + nums[i])) {
                    return true;
                }
                visited[i] = false;
            }

            return false;
        };
        return f(0, 0, 0);
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        return dfs(nums, k);
    }
};