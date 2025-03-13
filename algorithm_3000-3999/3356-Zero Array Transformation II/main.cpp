class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        std::function<bool(int)> check = [&](int k) {
            int diffs[n];
            std::fill(diffs, diffs + n, 0);
            for (int i = 0; i < k; ++i) {
                int l = queries[i][0], r = queries[i][1], val = queries[i][2];
                if (l < n) {
                    diffs[l] += val;
                }
                if (r + 1 < n) {
                    diffs[r + 1] -= val;
                }
            }

            for (int i = 0, sum = 0; i < n; ++i) {
                sum += diffs[i];
                if (sum < nums[i]) {
                    return false;
                }
            }

            return true;
        };

        int lo = 0, hi = queries.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo < queries.size() ? lo : (check(lo) ? lo : -1);
    }
};
