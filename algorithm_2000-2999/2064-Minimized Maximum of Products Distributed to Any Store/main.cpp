class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        std::function<bool(int)> checkAtMost = [&](int target) {
            int cnt = 0;
            for (int quantity : quantities) {
                cnt += quantity / target + (quantity % target > 0 ? 1 : 0);
                if (cnt > n) {
                    return false;
                }
            }
            return true;
        };

        int lo = 1, hi = INT_MAX;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (checkAtMost(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
