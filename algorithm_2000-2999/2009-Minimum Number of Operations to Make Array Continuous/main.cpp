class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        std::sort(nums.begin(), nums.end());
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

        int ret = n;
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            for (; j < nums.size() && nums[j] - nums[i] + 1 <= n; ++j) {
                ret = std::min(ret, n - (j - i + 1));
            }
        }

        return ret;
    }
};
