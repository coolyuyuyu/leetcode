class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int ret = 0;
        for (int pos = 0, i = 0; i < nums.size(); ++i) {
            pos += nums[i];
            if (pos == 0) {
                ++ret;
            }
        }

        return ret;
    }
};
