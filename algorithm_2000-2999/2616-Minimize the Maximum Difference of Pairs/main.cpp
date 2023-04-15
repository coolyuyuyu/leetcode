class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) {
            return 0;
        }

        std::sort(nums.begin(), nums.end());

        std::function<bool(int)> f = [&nums, p](int maxDiff) {
            int numPairs = 0;
            for (int i = 1; i < nums.size(); ++i) {
                if ((nums[i] - nums[i - 1]) <= maxDiff) {
                    numPairs += 1;
                    i += 1;
                }

                if (p <= numPairs) {
                    return true;
                }
            }

            return false;
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
