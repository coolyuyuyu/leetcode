class Solution {
public:
    int singleNumber(vector<int>& nums) {
        assert(!nums.empty());

        int ret = 0;
        for (int num : nums) {
            ret ^= num;
        }

        return ret;
    }
};
