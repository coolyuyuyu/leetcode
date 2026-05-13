class Solution {
public:
    int M = 1e9 + 7;

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        std::function<int(int, int)> quickPow = [&](int base, int exp) -> int {
            int ret = 1;
            for (; exp; exp >>= 1) {
                if (exp & 1) {
                    ret = 1L * ret * base % M;
                }
                base = 1L * base * base % M;
            }

            return ret;
        };

        std::function<int(int)> inv = [&](int x) {
            return quickPow(x, M - 2);
        };

        int n = nums.size();

        unordered_map<int, vector<tuple<int, int, int>>> k2queries;
        for (const auto& query : queries) {
            int l = query[0], r = query[1], k = query[2], v = query[3];
            if (1L * k * k >= n) {
                for (int i = l; i <= r; i += k) {
                    nums[i] = 1L * nums[i] * v % M;
                }
            }
            else {
                k2queries[k].emplace_back(l, r, v);
            }
        }

        for (const auto& [k, queries] : k2queries) {
            int diffs[n];
            std::fill(diffs, diffs + n, 1);
            for (const auto& [l, r, v] : queries) {
                diffs[l] = 1L * diffs[l] * v % M;
                int end = l + ((r - l) / k + 1) * k;
                if (end < n) {
                    diffs[end] = 1L * diffs[end] * inv(v) % M;
                }
            }
            for (int i = 0; i < n; ++i) {
                if (i >= k) { diffs[i] = 1L * diffs[i] * diffs[i - k] % M; }
                nums[i] = 1L * nums[i] * diffs[i] % M;
            }
        }

        return std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());
    }
};
