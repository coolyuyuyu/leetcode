class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        for (int lftSum = 0, rhtSum = std::accumulate(nums.begin(), nums.end(), 0), i = 0; i < nums.size(); ++i) {
            lftSum += (i == 0 ? 0 : nums[i - 1]);
            rhtSum -= nums[i];
            if (lftSum == rhtSum) {
                return i;
            }
        }

        return -1;
    }
};
