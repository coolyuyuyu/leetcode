class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        std::function<bool(int)> checkSubarray = [&](int len) {
            vector<int> freq(31, 0);

            int sum = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0, num = nums[i]; num; ++j, num >>= 1) {
                    if (num & 1) {
                        if (++freq[j] == 1) {
                            sum += (1 << j);
                        }
                    }
                }

                if (i + 1 >= len) {
                    if (sum >= k) {
                        return true;
                    }
                }

                if (i + 1 >= len) {
                    for (int j = 0, num = nums[i - len + 1]; num; ++j, num >>= 1) {
                        if (num & 1) {
                            if (--freq[j] == 0) {
                                sum -= (1 << j);
                            }
                        }
                    }
                }
            }

            return false;
        };

        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (checkSubarray(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return checkSubarray(lo) ? lo : -1;
    }
};
