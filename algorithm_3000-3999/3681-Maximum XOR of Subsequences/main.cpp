class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        vector<int> basis(32, 0);
        for (int num : nums) {
            while (num) {
                int i = 32 - __builtin_clz(num) - 1;
                if (basis[i] == 0) {
                    basis[i] = num;
                    break;
                }
                num ^= basis[i];
            }
        }

        int ret = 0;
        for (int i = 31; i >= 0; i--) {
            ret = max(ret, ret ^ basis[i]);
        }
        return ret;
    }
};
