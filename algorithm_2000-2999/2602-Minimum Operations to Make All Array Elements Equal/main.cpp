class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        std::sort(nums.begin(), nums.end());
        vector<long long> presum(nums.size());
        for (size_t i = 0; i < presum.size(); ++i) {
            presum[i] = (i > 0 ? presum[i - 1] : 0) + nums[i];
        }

        vector<long long> ret(queries.size());
        for (size_t i = 0; i < queries.size(); ++i) {
            long long query = queries[i];
            size_t lftCnt = std::lower_bound(nums.begin(), nums.end(), query) - nums.begin();
            size_t rhtCnt = nums.size() - lftCnt;
            long long lftSum = lftCnt ? presum[lftCnt - 1] : 0;
            long long rhtSum = presum.back() - lftSum;
            ret[i] = query * lftCnt - lftSum + rhtSum - query * rhtCnt;
        }

        return ret;
    }
};
