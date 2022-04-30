class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());

        int sum = 0, minNum = INT_MAX;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0 && 0 < k) {
                --k;
                nums[i] = -nums[i];
            }
            minNum = std::min(minNum, nums[i]);

            sum += nums[i];
        }
        if (k % 2 == 1) {
            sum -= (2 * minNum);
        }

        return sum;
    }
};
