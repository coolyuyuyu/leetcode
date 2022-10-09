class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        std::sort(nums.begin(), nums.end());
        std::partial_sum(nums.begin(), nums.end(), nums.begin());

        vector<int> ans(queries.size());
        for (size_t i = 0; i < queries.size(); ++i) {
            ans[i] = std::upper_bound(nums.begin(), nums.end(), queries[i]) - nums.begin();
        }

        return ans;
    }
};
