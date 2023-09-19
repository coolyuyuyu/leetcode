class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        int n = nums.size();

        long long ret = 0;
        for (int i = 1; i <= n; ++i) {
            long long sum = 0;
            for (int j = 1; i * j * j <= n; ++j) {
                sum += nums[i * j * j - 1];
            }
            ret = std::max(ret, sum);
        }

        return ret;
    }
};
