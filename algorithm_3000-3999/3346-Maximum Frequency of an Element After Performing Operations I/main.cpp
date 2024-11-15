class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());

        int ret = 0;

        // change num into existing element of nums
        unordered_map<int, int> cnts;
        for (int i = 0, lft = 0, rht = 0, n = nums.size(); i < n; ++i) {
            while (rht < n && nums[i] + k >= nums[rht]) {
                ++cnts[nums[rht]];
                ++rht;

            }
            while (lft < n && nums[lft] + k < nums[i]) {
                ++lft;
            }

            ret = std::max(ret, std::min(rht - lft, cnts[nums[i]] +numOperations));
        }

        // change num into non-existing element of nums
        for (int i = 0, j = 0, n = nums.size(); i < n; ++i) {
            while (j < n && (nums[j] - nums[i] <= 2 * k)) {
                ++j;
            }

            ret = std::max(ret, std::min(j - i, numOperations));
        }

        return ret;
    }
};
