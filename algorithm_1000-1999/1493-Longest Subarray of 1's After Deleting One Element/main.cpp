class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int ret = 0;
        for (int lft = 0, rht = 0, zeroCnt = 0; lft < n; ++lft) {
            while (rht < n && (nums[rht] == 1 || zeroCnt == 0)) {
                if (nums[rht] == 0) {
                    ++zeroCnt;
                }
                ++rht;
            }

            // sliding window with at most one 0
            ret = std::max(ret, rht - lft - 1);

            if (nums[lft] == 0) {
                --zeroCnt;
            }
        }

        return ret;
    }
};

