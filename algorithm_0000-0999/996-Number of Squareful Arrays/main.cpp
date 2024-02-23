class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
        int n = nums.size();

        std::sort(nums.begin(), nums.end());

        vector<int> graph[n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) { continue; }
                int sum = nums[i] + nums[j];
                if (floor(sqrt(sum)) == ceil(sqrt(sum))) {
                    graph[i].push_back(j);
                }
            }
        }

        // binary representation. ith bit = 1 => nums[i] is used
        int state = 0;

        int ret = 0;
        std::function<void(int, int)> dfs = [&](int cur, int cnt) {
            if (cnt >= n) {
                ++ret;
                return;
            }

            int prev = -1;
            for (int nxt : graph[cur]) {
                if (state & (1 << nxt)) { continue; }
                if (nums[nxt] == prev) { continue; }
                state |= (1 << nxt);
                dfs(nxt, cnt + 1);
                state &= ~(1 << nxt);
                prev = nums[nxt];
            }

        };
        for (int cur = 0, prev = -1; cur < n; ++cur) {
            if (nums[cur] == prev) { continue; }
            state |= (1 << cur);
            dfs(cur, 1);
            state &= ~(1 << cur);
            prev = nums[cur];
        }

        return ret;
    }
};
