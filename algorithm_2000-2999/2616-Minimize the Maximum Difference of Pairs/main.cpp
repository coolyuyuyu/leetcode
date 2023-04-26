class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        std::sort(nums.begin(), nums.end());

        auto f = [&nums, p](int maxDiff) {
            int numPairs = 0;
            for (int i = 1; i < nums.size() && numPairs < p; ++i) {
                if ((nums[i] - nums[i - 1]) <= maxDiff) {
                    ++i;
                    ++numPairs;
                }
            }

            return p <= numPairs;
        };

        int lo = 0, hi = 1e9;
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
