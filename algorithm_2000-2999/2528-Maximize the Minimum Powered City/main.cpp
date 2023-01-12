class Solution {
    typedef long long LL;

public:
    bool isOk(vector<int> stations, LL targetPower, LL r, LL k) {
        LL n = stations.size();

        LL power = std::accumulate(stations.begin(), stations.begin() + r, 0LL);
        for (LL i = 0; i < n; ++i) {
            if ((i + r) < n) {
                power += stations[i + r];
            }

            if (power < targetPower) {
                LL diff = targetPower - power;
                if ((k -= diff) < 0) {
                    return false;
                }

                stations[std::min(i + r, n - 1)] += diff;
                power = targetPower;
            }

            if (0 <= (i - r)) {
                power -= stations[i - r];
            }
        }

        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        LL lft = *std::min_element(stations.begin(), stations.end()), rht = 1e10 + 1e9;
        while (lft < rht) {
            LL mid = rht - (rht - lft) / 2;
            if (isOk(stations, mid, r, k)) {
                lft = mid;
            }
            else {
                rht = mid - 1;
            }
        }

        return lft;
    }
};
