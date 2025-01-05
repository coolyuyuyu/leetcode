class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ret = 0;
        for (long i = 0, lftSum = 0, rhtSum = std::accumulate(nums.begin(), nums.end(), 0L); i + 1 < nums.size(); ++i) {
            lftSum += nums[i];
            rhtSum -= nums[i];
            if (lftSum >= rhtSum) {
                ++ret;
            }
        }

        return ret;
    }
};
