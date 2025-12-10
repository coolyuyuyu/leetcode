class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        std::function<bool(long long)> f = [&](long long t) {
            long long sum = 0;
            int cnt = 0;
            for (int battery : batteries) {
                sum += std::min<long long>(battery, t);
                if (sum >= t) {
                    sum -= t;
                    if (++cnt >= n) {
                        return true;
                    }
                }
            }

            return false;
        };

        long long lo = 0, hi = LLONG_MAX;
        while (lo < hi) {
            long long mid = hi - (hi - lo) / 2;
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
