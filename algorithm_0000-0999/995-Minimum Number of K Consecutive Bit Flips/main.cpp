class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        int diffs[n];
        std::fill(diffs, diffs + n, 0);

        int ret = 0;
        for (int i = 0, sum = 0; i < n; ++i) {
            sum += diffs[i];
            if (nums[i] != (sum & 1)) { continue; }

            if (i + k > n) {
                return -1;
            }

            ++ret;

            sum += 1;
            if (i + k < n) {
                diffs[i + k] -= 1;
            }
        }

        return ret;
    }
};
