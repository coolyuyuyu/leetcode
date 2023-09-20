class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // find len of longest subarray whose sum == k, k = (sum(nums) - x)
        int k = std::accumulate(nums.begin(), nums.end(), 0) - x;

        int n = nums.size();
        unordered_map<int, int> presum2idx = {{0, -1}};
        int ret = INT_MAX;
        for (int i = 0, presum = 0; i < n; ++i) {
            presum += nums[i];

            auto itr = presum2idx.find(presum - k);
            if (itr != presum2idx.end()) {
                ret = std::min(ret, n - (i - itr->second));
            }

            presum2idx.emplace(presum, i);
        }

        return ret == INT_MAX ? -1 : ret;
    }
};
