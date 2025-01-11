class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());

        // X  X  X  ... X  X  X
        // +k +k +k     -k -k -k

        int ret = nums.back() - nums.front();
        for (int i = 0, n = nums.size(); i + 1 < n; ++i) {
            int mx = std::max(nums[i] + k, nums.back() - k);
            int mn = std::min(nums.front() + k, nums[i + 1] - k);
            ret = std::min(ret, mx - mn);
        }

        return ret;
    }
};
