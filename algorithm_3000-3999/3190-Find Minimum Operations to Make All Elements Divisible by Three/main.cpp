class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ret = 0;
        for (int num : nums) {
            if (num % 3 != 0) {
                ++ret;
            }
        }

        return ret;
    }
};
