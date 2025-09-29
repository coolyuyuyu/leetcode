class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();

        bool lftInc[n];
        lftInc[0] = true;
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] < nums[i]) {
                lftInc[i] = true;
            }
            else {
                std::fill(lftInc + i, lftInc + n, false);
                break;
            }
        }

        bool rhtDec[n];
        rhtDec[n - 1] = true;
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] > nums[i + 1]) {
                rhtDec[i] = true;
            }
            else {
                std::fill(rhtDec + 0, rhtDec + i + 1, false);
                break;
            }
        }

        long long presums[n];
        for (int i = 0; i < n; ++i) {
            presums[i] = (i > 0 ? presums[i - 1] : 0) + nums[i];
        }
        std:function<long long(int, int)> sum = [&](int lo, int hi) {
            return presums[hi] - (lo > 0 ? presums[lo - 1] : 0);
        };

        long long ret = LLONG_MAX;
        for (int i = 0; i + 1 < n; ++i) {
            if (lftInc[i] && rhtDec[i + 1]) {
                ret = std::min(ret, std::abs(sum(0, i) - sum(i + 1, n - 1)));
            }
        }

        return ret != LLONG_MAX ? ret : -1;
    }
};
