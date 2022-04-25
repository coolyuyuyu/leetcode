class Solution {
public:
    bool divideArray(vector<int>& nums) {
        bitset<500> flags;
        for (int num : nums) {
            flags[num - 1].flip();
        }

        return !flags.any();
    }
};
