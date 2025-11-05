class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);

        int ret = 0;
        for (int lftSum = 0, rhtSum = sum, i = 0, n = nums.size(); i < n; ++i) {
            lftSum += nums[i], rhtSum -= nums[i];
            if (nums[i] != 0) { continue; }

            if (lftSum == rhtSum) {
                ret += 2;
            }
            else if (std::abs(lftSum - rhtSum) == 1) {
                ret += 1;
            }
        }

        return ret;
    }
};
