class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        std::sort(nums.begin(), nums.end());
        std::partial_sum(nums.begin(), nums.end(), nums.begin());

        size_t n = queries.size();
        vector<int> ret(queries.size());
        for (size_t i = 0; i < n; ++i) {
            ret[i] = std::upper_bound(nums.begin(), nums.end(), queries[i]) - nums.begin();
        }

        return ret;
    }
};
