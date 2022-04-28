class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int lftSum = 0, rhtSum = sum, i = 0; i < nums.size(); ++i) {
            lftSum += (0 < i ? nums[i - 1] : 0);
            rhtSum -= nums[i];
            if (lftSum == rhtSum) {
                return i;
            }
        }

        return -1;
    }
};
