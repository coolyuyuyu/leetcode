class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        std::function<bool(long long)> checkOk = [&](long long t) {
            long long cnt = 0;
            for (int rank : ranks) {
                if (t >= rank) {
                    cnt += sqrt(t / rank);
                    if (cnt >= cars) {
                        return true;
                    }
                }
            }

            return false;
        };

        long long lo = 1, hi = LLONG_MAX;
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
