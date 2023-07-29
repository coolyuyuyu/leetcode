class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        std::function<bool(int, long long)> f = [&batteries](int n, long long t)  {
            long long sum = 0;
            for (int battery : batteries) {
                sum += std::min<long long>(battery, t);
                if (t <= sum) {
                    sum -= t;
                    if (--n == 0) {
                        return true;
                    }
                }
            }
            return false;
        };

        long long lo = 1, hi = LLONG_MAX;
        while (lo < hi) {
            long long mid = hi - (hi - lo) / 2;
            if (f(n, mid)) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }

        return lo;
    }
};
