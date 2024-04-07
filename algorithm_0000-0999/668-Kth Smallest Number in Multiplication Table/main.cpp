class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        std::function<int(int)> countLE = [&](int target) {
            int cnt = 0;
            for (int r = 1; r <= m; ++r) {
                cnt += std::min(target / r, n);
            }

            return cnt;
        };

        int lo = 1, hi = m * n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (countLE(mid) >= k) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
