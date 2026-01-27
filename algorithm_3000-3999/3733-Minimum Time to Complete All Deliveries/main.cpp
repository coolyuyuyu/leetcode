class Solution {
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
        int d1 = d[0], d2 = d[1];
        int r1 = r[0], r2 = r[1];

        std::function<bool(long long)> checkOk = [&](long long t) {
            long long v1 = t - t / r1;
            long long v2 = t - t / r2;
            long long v = t - t / std::lcm(r1, r2);
            return v1 >= d1 && v2 >= d2 && v >= (d1 + d2);
        };

        long long lo = 0, hi = LLONG_MAX;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (checkOk(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
