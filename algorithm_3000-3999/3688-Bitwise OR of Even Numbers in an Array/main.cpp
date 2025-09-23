class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int ret = 0;
        for (int num : nums) {
            if (num & 1) { continue; }
            ret |= num;
        }

        return ret;
    }
};
