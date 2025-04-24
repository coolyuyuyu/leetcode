class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> m = {{0, -1}}; // <presum, idx>

        int ret = 0;
        long sum = 0;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            sum += nums[i];

            if (m.find(sum - k) != m.end()) {
                ret = std::max(ret, i - m[sum - k]);
            }

            m.emplace(sum, i);
        }

        return ret;
    }
};
