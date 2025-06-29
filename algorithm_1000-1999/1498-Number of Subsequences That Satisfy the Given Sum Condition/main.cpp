class Solution {
public:
    int M = 1e9 + 7;

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();

        std::sort(nums.begin(), nums.end());

        int power2[n];
        power2[0] = 1;
        for (int i = 1; i < n; ++i) {
            power2[i] = 1L * power2[i - 1] * 2 % M;
        }

        int ret = 0;
        for (int i = 0, j = n - 1; i <= j; ++i) {
            while (i <= j && nums[i] + nums[j] > target) {
                --j;
            }
            if (i > j) break;

            ret = (ret + power2[j - i]) % M;
        }

        return ret;
    }
};
