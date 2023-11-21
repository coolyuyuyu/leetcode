class Solution {
public:
    int M = 1e9 + 7;

    int countNicePairs(vector<int>& nums) {
        // nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
        // => nums[i] - rev(nums[i]) == nums[j] - rev(nums[j]);

        unordered_map<int, int> m;
        for (int num : nums) {
            int rev = 0;
            for (int x = num; x; x /= 10) {
                rev *= 10;
                rev += x % 10;
            }

            ++m[num - rev];
        }

        int ret = 0;
        for (const auto [_, cnt] : m) {
            ret += 1L * cnt * (cnt - 1) / 2 % M;
            ret %= M;
        }

        return ret;
    }
};
