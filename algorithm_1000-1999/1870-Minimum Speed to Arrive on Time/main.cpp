class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (dist.size() > 1 && hour <= dist.size() - 1) { return -1; }

        std::function<bool(int)> arriveInTime = [&](int speed) {
            double h = 0;
            for (int i = 0; i + 1 < dist.size(); ++i) {
                h += (dist[i] + (speed - 1)) / speed;
                if (h > hour) { return false; }
            }
            h += 1.0 * dist.back() / speed;

            return h <= hour;
        };

        int lo = 1, hi = 1e7;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (arriveInTime(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
