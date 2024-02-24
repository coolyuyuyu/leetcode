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

    int minimumIncompatibility(vector<int>& nums, int k) {
        return byDFS(nums, k);
    }
};
