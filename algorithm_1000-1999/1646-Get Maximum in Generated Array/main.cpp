class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n <= 0) {
            return 0;
        }

        vector<int> nums(n + 1);
        nums[0] = 0, nums[1] = 1;

        int maxNum = 1;
        for (int i = 1; i <= (n / 2);  ++i) {
            nums[2 * i] = nums[i];
            if ((2 * i + 1) < nums.size()) {
                nums[2 * i + 1] = nums[i] + nums[i + 1];
                maxNum = std::max(maxNum, nums[2 * i + 1]);
            }
        }

        return maxNum;
    }
};
