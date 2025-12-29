class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();

        long long presum = std::accumulate(nums.begin(), nums.end(), 0LL);
        long long sufmin = LLONG_MAX;

        long long ret = LLONG_MIN;
        for (int i = n - 2; i >= 0; --i) {
            presum -= nums[i + 1];
            sufmin = std::min<long long>(sufmin, nums[i + 1]);

            ret = std::max(ret, presum - sufmin);
        }

        return ret;
    }
};
