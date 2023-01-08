class Solution {
public:
    typedef long long LL;

    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();

        vector<LL> ss(stations.begin(), stations.end());
        std::partial_sum(ss.begin(), ss.end(), ss.begin());

        vector<LL> powers(n, 0);
        for (int i = 0; i < n; ++i) {
            if ((i + r) < n) {
                powers[i] += ss[i + r];
            }
            else {
                powers[i] += ss.back();
            }

            if (0 <= (i - r - 1)) {
                powers[i] -= ss[i - r - 1];
            }
        }

        LL windowSize = 2 * r + 1;
        auto isOk = [&powers, &windowSize, &n, &k](LL target) -> bool {
            vector<LL> diffs(n, 0);
            LL count = 0;
            LL curSum = 0;
            for (int i = 0; i < n; ++i) {
                curSum += diffs[i];
                LL power = powers[i] + curSum;
                if (power < target) {
                    count += (target - power);
                    curSum += (target - power);
                    if (count > k) {
                        return false;
                    }
                    if ((i + windowSize) < n) {
                        diffs[i + windowSize] -= (target - power);
                    }
                }
            }

            return true;
        };

        LL lft = *std::min_element(powers.begin(), powers.end()), rht = 1e10 + 1e9;
        while (lft < rht) {
            LL mid = rht - (rht - lft) / 2;
            if (isOk(mid)) {
                lft = mid;
            }
            else {
                rht = mid - 1;
            }
        }

        return lft;
    }
};
