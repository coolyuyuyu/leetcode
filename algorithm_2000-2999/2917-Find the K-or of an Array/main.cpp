class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int n = nums.size();

        if (k == n) {
            int ret = ~0;
            for (int num : nums) {
                ret &= num;
            }
            return ret;
        }

        int cnts[32];
        std::fill(cnts, cnts + 32, 0);
        for (int num : nums) {
            for (int i = 0; i < 32; ++i) {
                cnts[i] += (num >> i) & 1 ? 1 : 0;
            }
        }

        int ret = 0;
        for (int i = 0; i < 32; ++i) {
            if (cnts[i] >= k) {
                ret += (1 << i);
            }
        }

        return ret;
    }
};
