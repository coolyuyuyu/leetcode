class Solution {
public:
    long long subsequenceSumOr(vector<int>& nums) {
        long long ret = 0;

        for (int num : nums) {
            ret |= num;
        }

        long long presum = 0;
        for (int num : nums) {
            presum += num;
            ret |= presum;
        }

        return ret;
    }
};
