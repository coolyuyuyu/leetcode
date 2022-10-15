class Solution {
public:

    void recursive(vector<int>& nums, vector<bool>& flags, size_t depth, int& xorSum) {
        if (nums.size() <= depth) {
            int x = 0;
            for (size_t i = 0; i < flags.size(); ++i) {
                if (flags[i]) {
                    x ^= nums[i];
                }
            }
            xorSum += x;

            return;
        }

        flags[depth] = false;
        recursive(nums, flags, depth + 1, xorSum);
        flags[depth] = true;
        recursive(nums, flags, depth + 1, xorSum);
    }

    int bitmask1(vector<int>& nums) {
        int xorSum = 0;
        for (int mask  = 1; mask < (1 << nums.size()); ++mask) {
            int s = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (mask & (1 << i)) {
                    s ^= nums[i];
                }
            }
            xorSum += s;
        }

        return xorSum;
    }

    int bitmask2(vector<int>& nums) {
        return std::accumulate(nums.begin(), nums.end(), 0, bit_or<int>()) << (nums.size() - 1);
    }

    int subsetXORSum(vector<int>& nums) {
        //vector<bool> flags(nums.size(), false);
        //int xorSum = 0;
        //recursive(nums, flags, 0, xorSum);
        //return xorSum;

        //return bitmask1(nums);

        return bitmask2(nums);
    }
};
