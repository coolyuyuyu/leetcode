class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ret = 0;
        int cnt0 = 0;
        for (int num : nums) {
            if (num == 0) {
                ++cnt0;
            }
            else {
                cnt0 = 0;
            }
            ret += cnt0;
        }

        return ret;
    }
};
