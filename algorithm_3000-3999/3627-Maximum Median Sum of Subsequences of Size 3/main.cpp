class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        long long ret = 0;
        for (int n = nums.size(), i = n - 2, cnt = 0; cnt * 3 < n; i -= 2, ++cnt) {
            ret += nums[i];
        }

        return ret;
    }
};
