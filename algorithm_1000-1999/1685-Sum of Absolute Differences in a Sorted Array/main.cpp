class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();

        int presum[n];
        std::partial_sum(nums.begin(), nums.end(), presum);
        std::function<int(int, int)> sum = [&](int lo, int hi) {
            if (lo > hi) {
                return 0;
            }
            else {
                return presum[hi] - (lo == 0 ? 0 : presum[lo - 1]);
            }
        };

        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            ret[i] = nums[i] * i - sum(0, i - 1) + sum(i + 1, n - 1) - nums[i] * (n - i - 1);
        }

        return ret;
    }
};
