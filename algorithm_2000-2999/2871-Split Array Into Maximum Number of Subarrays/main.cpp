class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int sum = INT_MAX;
        for (int num : nums) {
            sum &= num;
        }
        if (sum > 0) {
            return 1;
        }

        int ret = 0;
        for (int i = 0; i < nums.size();) {
            int s = INT_MAX;
            while (s != 0 && i < nums.size()) {
                s &= nums[i++];
            }
            if (s == 0) {
                ++ret;
            }
        }

        return ret;
    }
};
