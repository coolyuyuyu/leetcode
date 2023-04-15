class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size(), 1);
        for (int i = 0, prefix = 1; i < nums.size(); ++i) {
            ret[i] *= prefix;
            prefix *= nums[i];
        }
        for (int i = nums.size(), suffix = 1; 0 < i--;) {
            ret[i] *= suffix;
            suffix *= nums[i];
        }

        return ret;
    }
};
