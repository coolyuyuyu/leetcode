class Solution {
public:
    double byDP(vector<int>& nums, int k) {
        int n = nums.size();

        int presums[n];
        std::partial_sum(nums.begin(), nums.end(), presums);

        double maxAvg = -DBL_MAX;
        for (int rht = k - 1, preLft = 0; rht < n; ++rht) {
            for (int lft = preLft; rht - lft + 1 >= k; ++lft) {
                double avg = (presums[rht] - (lft > 0 ? presums[lft - 1] : 0)) * 1.0 / (rht - lft + 1);
                if (avg > maxAvg) {
                    preLft = lft;
                    maxAvg = avg;
                }
            }
        }

        return maxAvg;
    }

    double byBSearch(vector<int>& nums, int k) {
        int n = nums.size();
        auto [ilo, ihi] = std::minmax_element(nums.begin(), nums.end());
        double lo = *ilo, hi = *ihi;

        std::function<bool(double)> isAvgGT = [&](double target) {
            vector<double> presums(nums.size());
            for (int i = 0; i < n; ++i) {
                presums[i] = (i > 0 ? presums[i - 1] : 0.0) + nums[i] - target;
            }

            double minPresum = 0.0;
            for (int rht = k - 1; rht < n; ++rht) {
                if (presums[rht] > minPresum) {
                    return true;
                }

                minPresum = std::min(minPresum, presums[rht - k + 1]);
            }

            return false;
        };

        while (lo + 1e-5 < hi) {
            double mid = (lo + hi) / 2;
            if (isAvgGT(mid)) {
                lo = mid;
            }
            else {
                hi = mid;
            }
        }

        return lo;
    }

    double findMaxAverage(vector<int>& nums, int k) {
        //return byDP(nums, k);
        return byBSearch(nums, k);
    }
};
