class Solution {
public:
    int minOrAfterOperations(vector<int>& nums, int k) {
        int n = nums.size();

        int arr[n];
        std::fill(arr, arr + n, 0);

        std::function<bool()> checkOk = [&]() {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                int sum = (1 << 30) - 1;
                for (; i < n && (sum & arr[i]); ++i) {
                    sum &= arr[i];
                    ++cnt;
                }
            }

            return cnt != n && cnt <= k;
        };

        int ret = 0;
        for (int j = 29; j >= 0; j--) {
            for (int i = 0; i < n; ++i) {
                arr[i] <<= 1;
                arr[i] |= (nums[i] >> j) & 1;
            }

            if (!checkOk()) {
                ret |= (1 << j);
                for (int i = 0; i < n; ++i) {
                    arr[i] >>= 1;
                }
            }
        }

        return ret;
    }
};
