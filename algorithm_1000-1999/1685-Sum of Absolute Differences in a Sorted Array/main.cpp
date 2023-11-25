class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();

        vector<int> ret(n);
        ret[0] = std::accumulate(nums.begin(), nums.end(), 0) - nums[0] * n;
        for (int i = 1; i < n; ++i) {
            int diff = nums[i] - nums[i - 1];
            ret[i] = ret[i - 1] + diff * i - diff * (n - i);
        }

        return ret;
    }
};
