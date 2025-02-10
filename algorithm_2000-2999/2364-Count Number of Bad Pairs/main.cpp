class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();

        // j - i == nums[j] - nums[i]
        // => i - nums[i] == j - nums[j]
        long long ret = 0;
        unordered_map<int, int> m;
        for (int j = 0; j < n; ++j) {
            ret += m[j - nums[j]];
            ++m[j - nums[j]];
        }

        return 1L * n * (n - 1) / 2 - ret;
    }
};
