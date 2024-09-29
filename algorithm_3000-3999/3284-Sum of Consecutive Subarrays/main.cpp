class Solution {
public:
    int M = 1e9 + 7;

    int getSum(vector<int>& nums) {
        long sum1 = nums[0], sum2 = nums[0], cnt1 = 1, cnt2 = 1;
        long ret = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] + 1 != nums[i]) {
                sum1 = 0, cnt1 = 0;
            }
            sum1 = (sum1 + (++cnt1 * nums[i]) % M) % M;
            ret = (ret + sum1) % M;

            if (nums[i - 1] - 1 != nums[i]) {
                sum2 = 0, cnt2 = 0;
            }
            sum2 = (sum2 + ++cnt2 * nums[i]) % M;
            ret = (ret + sum2) % M;

            ret = (ret - nums[i] + M) % M;
        }

        return ret;
    }
};
