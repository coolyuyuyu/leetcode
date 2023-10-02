class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end());

        vector<long long> presum(2 * n);
        presum[0] = nums[0];
        for (int i = 1; i < 2 * n; ++i) {
            presum[i] = presum[i - 1] + nums[i];
        }
        long long sum = presum[n - 1];

        int ret = INT_MAX;

        unordered_map<long long, int> m = {{0, -1}}; // presum % sum, index
        for (int i = 0; i < 2 * n; ++i) {
            // presum[i] - presum[j] + sum * k = target
            // presum[j] = presum[i] - target + sum * k

            long long r = (presum[i] - target) % sum;
            r = (r + sum) % sum;

            if (m.find(r) != m.end()) {
                int j = m[r];
                int k = ((j == -1 ? 0 : presum[j]) - presum[i] + target) / sum;
                ret = std::min(ret, i - j + k * n);
            }

            m[presum[i] % sum] = i;
        }

        return ret == INT_MAX ? -1 : ret;
    }
};
