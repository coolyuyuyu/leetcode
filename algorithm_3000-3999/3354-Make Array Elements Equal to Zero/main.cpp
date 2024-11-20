class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();

        int presums[n];
        std::partial_sum(nums.begin(), nums.end(), presums);
        int sum = presums[n - 1];

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                int lftSum = presums[i], rhtSum = sum - lftSum - nums[i];
                if (lftSum == rhtSum) {
                    ret += 2;
                }
                else if (std::abs(lftSum - rhtSum) == 1) {
                    ret += 1;
                }
            }
        }

        return ret;
    }
};
