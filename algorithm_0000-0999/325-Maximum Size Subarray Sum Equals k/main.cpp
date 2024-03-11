class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<long, int> presum2idx = {{0, -1}};

        int ret = 0;
        long presum = 0;
        for (int i = 0; i < n; ++i) {
            presum += nums[i];
            if (presum2idx.find(presum - k) != presum2idx.end()) {
                ret = std::max(ret, i - presum2idx[presum - k]);
            }

            presum2idx.emplace(presum, i);
        }

        return ret;
    }
};
