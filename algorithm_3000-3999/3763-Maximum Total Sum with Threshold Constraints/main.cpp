class Solution {
public:
    long long maxSum(vector<int>& nums, vector<int>& threshold) {
        int n = nums.size();

        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; ++i) {
            pairs[i] = {threshold[i], nums[i]};
        }
        std::sort(pairs.begin(), pairs.end());

        long long ret = 0;

        int step = 1;
        for (const auto& [t, num] : pairs) {
            if (step < t) { break; }
            ret += num;
            step++;
        }

        return ret;
    }
};
