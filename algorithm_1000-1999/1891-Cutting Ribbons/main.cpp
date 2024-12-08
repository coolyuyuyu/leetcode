class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        std::function<bool(int)> f = [&](int target) {
            int cnt = 0;
            for (int len : ribbons) {
                cnt += (len / target);
                if (cnt >= k) {
                    return true;
                }
            }
            return false;
        };

        int lo = 0, hi = *std::max_element(ribbons.begin(), ribbons.end());
        while (lo < hi) {
            int mid = hi - (hi - lo) / 2;
            if (f(mid)) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }

        return lo;
    }
};
