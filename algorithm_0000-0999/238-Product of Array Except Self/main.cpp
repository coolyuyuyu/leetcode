class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> ret(n, 1);
        for (int i = 0, prefix = 1; i < n; ++i) {
            ret[i] *= prefix;
            prefix *= nums[i];
        }
        for (int i = n, suffix = 1; 0 < i--;) {
            ret[i] *= suffix;
            suffix *= nums[i];
        }

        return ret;
    }
};
