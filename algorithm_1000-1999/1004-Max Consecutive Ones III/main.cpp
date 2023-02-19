class Solution {
public:
    // two pointers
    // Time: O(n)
    int longestOnes(vector<int>& nums, int k) {
        int ret = 0;
        for (int lft = 0, rht = 0, n = nums.size(); lft < n; ++lft) { // [lft, rht)
            for (; rht < n && (nums[rht] == 1 || 0 < k); ++rht) {
                if (nums[rht] == 0) {
                    --k;
                }
            }
            ret = std::max(ret, rht - lft);

            if (nums[lft] == 0) {
                ++k;
            }
        }

        return ret;
    }
};
