class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ret = 0;
        for (int num : nums) {
            if (num < k) {
                ++ret;
            }
        }

        return ret;
    }
};
