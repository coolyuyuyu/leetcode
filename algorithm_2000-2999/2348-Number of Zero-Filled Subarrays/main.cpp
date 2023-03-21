class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ret = 0;
        int count = 0;
        for (int num : nums) {
            if (num == 0) {
                ++count;
            }
            else {
                count = 0;
            }

            ret += count;
        }

        return ret;
    }
};
