class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.reserve(pow(2, nums.size()));
        if (!nums.empty()) {
            ans.push_back({});
            ans.push_back({nums[0]});
        }

        for (size_t i = 1; i < nums.size(); ++i) {
            size_t n = ans.size();
            ans.insert(ans.end(), ans.begin(), ans.end());

            for (size_t j = 0; j < n; ++j) {
                ans[j].push_back(nums[i]);
            }
        }

        return ans;
    }
};