class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();

        for (int s = 1; s + 1 < (1 << n); ++s) {
            long long a = target, b = target;

            bool divisible = true;
            for (int i = 0; i < n && divisible; ++i) {
                long long& x = ((s >> i) & 1) ? a : b;
                if (x % nums[i] != 0) {
                    divisible = false;
                }
                x /= nums[i];
            }
            if (!divisible) {
                continue;
            }

            if (a == 1 && b == 1) {
                return true;
            }

        }

        return false;
    }
};
