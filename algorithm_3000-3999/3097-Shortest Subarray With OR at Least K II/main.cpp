class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int cnts[32];
        std::function<bool(int)> checkOk = [&](int len) {
            std::fill(cnts, cnts + 32, 0);

            for (int i = 0, sum = 0; i < n; ++i) {
                for (int j = 0, num = nums[i]; num; j++, num >>= 1) {
                    if ((num & 1) && ++cnts[j] == 1) {
                        sum |= (1 << j);
                    }
                }

                if (i + 1 >= len) {
                    if (sum >= k) {
                        return true;
                    }

                    for (int j = 0, num = nums[i + 1 - len]; num; j++, num >>= 1) {
                        if ((num & 1) && --cnts[j] == 0) {
                            sum &= ~(1 << j);
                        };
                    }
                }
            }

            return false;
        };

        int lo = 1, hi = nums.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (checkOk(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return checkOk(lo) ? lo : -1;
    }
};
