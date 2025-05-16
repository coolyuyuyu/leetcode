class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ret(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            ret[i] = nums[nums[i]];
        }

        return ret;
    }
};
