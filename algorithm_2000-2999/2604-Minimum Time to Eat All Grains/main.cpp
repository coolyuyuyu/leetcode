class Solution {
public:
    
    int minimumTime(vector<int>& hens, vector<int>& grains) {
        std::sort(hens.begin(), hens.end());
        std::sort(grains.begin(), grains.end());

        std::function<bool(int)> f = [&hens, &grains](int time) {
            for (int i = 0, j = 0; i < hens.size(); ++i) {
                int t = (grains[j] < hens[i] ? (hens[i] - grains[j]) : 0);
                if (time < t) {
                    return false;
                }

                while (j < grains.size() && grains[j] < hens[i]) {
                    ++j;
                }
                if (3 * t < time) {
                    while (j < grains.size() && (t * 2 + (grains[j] - hens[i])) <= time) {
                        ++j;
                    }
                }
                else {
                    while (j < grains.size() && (t + (grains[j] - hens[i]) * 2) <= time) {
                        ++j;
                    }
                }

                if (j == grains.size()) {
                    return true;
                }
            }

            return false;
        };

        int lo = 0, hi = INT_MAX;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (f(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
