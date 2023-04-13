class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        map<int, vector<long long>> m;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]].push_back(i);
        }

        vector<long long> ret(nums.size());
        for (auto& [_, indexes] : m) {
            int n = indexes.size();

            vector<long long> presum(n);
            std::partial_sum(indexes.begin(), indexes.end(), presum.begin());
            for (int i = 0; i < n; ++i) {
                long long lftSum = (0 < i ? presum[i - 1] : 0);
                long long rhtSum = presum.back() - presum[i];
                ret[indexes[i]] = (indexes[i] * i - lftSum) + (rhtSum - indexes[i] * (n - i - 1));
            }
        }

        return ret;
    }
};
