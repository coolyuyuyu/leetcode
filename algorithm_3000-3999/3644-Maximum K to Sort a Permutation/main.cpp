class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ret = INT_MAX;
        bool isSorted = true;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            if (nums[i] != i) {
                ret &= nums[i];
                isSorted = false;
            }
        }

        return isSorted ? 0 : ret;
    }
};
