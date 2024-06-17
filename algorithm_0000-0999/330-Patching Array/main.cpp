class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1;
        int ret = 0;
        for (int i = 0; miss <= n;) {
            if (i >= nums.size() || miss < nums[i]) {
                miss += miss;
                ++ret;
            }
            else {
                miss += nums[i];
                ++i;
            }
        }

        return ret;
    }
};
