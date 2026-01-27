class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        // For any pair (a, b), let x = |a| and y = |b| and assume x <= y; the two conditions simplify to 2 * x >= y.

        std::sort(nums.begin(), nums.end(), [](int a, int b){ return abs(a) < abs(b); });

        long long ret = 0;
        for (int i = 0, j = 0, n = nums.size(); i < n; ++i) {
            while (j < n && 2 * abs(nums[i]) >= abs(nums[j])) {
                ++j;
            }

            ret += j - i - 1;
        }

        return ret;
    }
};
