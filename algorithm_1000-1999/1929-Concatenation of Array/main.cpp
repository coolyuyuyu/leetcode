class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(nums);
        ans.resize(nums.size() * 2);

        for (size_t i = 0; i < nums.size(); ++i) {
            ans[nums.size() + i] = nums[i];
        }

        return ans;
    }
};
