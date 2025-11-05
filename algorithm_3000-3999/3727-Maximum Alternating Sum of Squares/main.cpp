class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for (int& num : nums) {
            num *= num;
        }
        std::sort(nums.begin(), nums.end());

        int n = nums.size();

        long long ret = 0;
        for (int i = 0; i < n / 2; ++i) {
            ret -= nums[i];
        }
        for (int i = n / 2; i < n; ++i) {
            ret += nums[i];
        }

        return ret;
    }
};
