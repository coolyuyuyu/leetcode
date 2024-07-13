class Solution {
public:
    vector<int> orArray(vector<int>& nums) {
        vector<int> ret(nums.size() - 1);
        for (int i = 0; i + 1 < nums.size(); ++i) {
            ret[i] = nums[i] | nums[i + 1];
        }

        return ret;
    }
};
