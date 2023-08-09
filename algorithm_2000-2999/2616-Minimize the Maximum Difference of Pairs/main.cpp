class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        std::sort(nums.begin(), nums.end());

        std::function<bool(int)> f = [&](int maxDiff) {
            int cnt = 0;
            for (int i = 1; i < nums.size() && cnt < p; ++i) {
                if ((nums[i] - nums[i - 1]) <= maxDiff) {
                    ++cnt;
                    ++i;
                }
            }

            return p <= cnt;
        };

        int lo = 0, hi = nums.back() - nums.front();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (f(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
