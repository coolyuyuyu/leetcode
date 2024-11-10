class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();

        vector<int> ret(n);
        for (int i = 0, v = 0, maxK = (1 << maximumBit) - 1; i < n; ++i) {
            v ^= nums[i];
            ret[n - i - 1] = v ^ maxK;
        }

        return ret;
    }
};
