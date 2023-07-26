class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        std::function<bool(int)> makeIt = [&](int speed) -> bool {
            double h = 0.0;
            for (int i = 0; (i + 1) < dist.size(); ++i) {
                h += ((dist[i] - 1) / speed + 1);
                if (hour < h) {
                    return false;
                }
            }
            h += dist.back() * 1.0 / speed;

            return (h <= hour);
        };

        int lo = 1, hi = 1e7 + 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (makeIt(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return (lo < (1e7 + 1)) ? lo : -1;
    }
};
