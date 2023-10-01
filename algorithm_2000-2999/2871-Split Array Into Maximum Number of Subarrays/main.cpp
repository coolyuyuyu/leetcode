class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int n = nums.size();

        int ret = 0;
        for (int i = 0; i < n;) {
            int sum = INT_MAX;
            while (sum != 0 && i < n) {
                sum &= nums[i++];
            }
            if (sum == 0) {
                ++ret;
            }
        }

        return std::max(1, ret);
    }
};
