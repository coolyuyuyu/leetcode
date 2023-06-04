class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();

        int i1, i2;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                i1 = i;
            }
            else if (nums[i] == n) {
                i2 = i;
            }
        }

        if (i1 < i2) {
            return i1 + n - i2 - 1;
        }
        else {
            return i1 + n - i2 - 1 - 1;
        }
    }
};
