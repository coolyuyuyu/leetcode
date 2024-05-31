class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        std::function<bool(int)> canFinish = [&](int capacity) {
            int load = capacity;
            int d = 0;
            for (int weight : weights) {
                load += weight;
                if (load > capacity) {
                    if (++d > days) { return false; }
                    load = weight;
                }
            }

            return true;
        };

        int lo = INT_MIN, hi = 0;
        for (int weight : weights) {
            lo = std::max(lo, weight);
            hi = hi + weight;
        }
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canFinish(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
