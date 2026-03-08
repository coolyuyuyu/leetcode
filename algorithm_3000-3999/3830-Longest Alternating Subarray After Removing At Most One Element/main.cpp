class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        int n = nums.size();

        std::function<int(int, int)> cmp = [](int a, int b) {
            return (a > b) - (a < b);
        };

        //  lft[i]: maximum length of the alternating subarray to the lft
        int lft[n];
        lft[0] = 1;
        for (int i = 1; i < n; ++i) {
            int d = cmp(nums[i - 1], nums[i]);
            if (d != 0) {
                if (i >= 2 && cmp(nums[i - 2], nums[i - 1]) == -d) {
                    lft[i] = lft[i - 1] + 1;
                }
                else {
                    lft[i] = 2;
                }
            }
            else {
                lft[i] = 1;
            }
        }

        //  rht[i]: maximum length of the alternating subarray to the lft
        int rht[n];
        rht[0] = 1;
        for (int i = n - 2; i >= 0; --i) {
            int d = cmp(nums[i], nums[i + 1]);
            if (d != 0) {
                if (i + 2 < n && cmp(nums[i + 1], nums[i + 2]) == -d) {
                    rht[i] = rht[i + 1] + 1;
                }
                else {
                    rht[i] = 2;
                }
            }
            else {
                rht[i] = 1;
            }
        }

        int ret = *std::max_element(lft, lft + n);
        for (int i = 1; i + 1 < n; ++i) {
            int d = cmp(nums[i - 1], nums[i + 1]);
            if (d != 0) {
                int lLen = (i - 2 >= 0 && cmp(nums[i - 2], nums[i - 1]) == -d) ? (lft[i - 1]) : (1);
                int rLen = (i + 2 < n && cmp(nums[i + 1], nums[i + 2]) == -d) ? (rht[i + 1]) : (1);
                ret = std::max(ret, lLen + rLen);
            }
        }

        return ret;
    }
};