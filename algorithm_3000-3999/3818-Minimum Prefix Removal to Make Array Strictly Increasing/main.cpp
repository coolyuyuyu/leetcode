class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] >= nums[i + 1]) {
                return i + 1;
            }
        }

        return 0;
    }
};
