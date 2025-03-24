class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();

        int presums[n];
        std::partial_sum(nums.begin(), nums.end(), presums);
        std::function<int(int, int)> sum = [&](int lo, int hi) {
            return presums[hi] - (lo > 0 ? presums[lo - 1] : 0);
        };

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret += sum(std::max(0, i - nums[i]), i);
        }

        return ret;
    }
};
