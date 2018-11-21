class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        int xor0 = 0;
        for (int i = 1; i <= n; ++i) {
            xor0 ^= i;
            xor0 ^= nums[i - 1];
        }

        int xor1 = 0, xor2 = 0; {
            int rhtMostbit = xor0 & ~(xor0 -1);
            for (int i = 1; i <= n; ++i) {
                if (rhtMostbit & i) {
                    xor1 ^= i;
                }
                else {
                    xor2 ^= i;
                }

                if (rhtMostbit & nums[i - 1]) {
                    xor1 ^= nums[i - 1];
                }
                else {
                    xor2 ^= nums[i - 1];
                }
            }
        }

        for (auto num : nums) {
            if (num == xor1) {
                return { xor1, xor2 };
            }
            else if (num == xor2) {
                return { xor2, xor1 };
            }
        }

        assert(false);
        return { -1, -1 };
    }
};
