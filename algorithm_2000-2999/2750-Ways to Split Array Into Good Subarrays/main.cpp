class Solution {
public:
    int M = 1e9 + 7;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int lft = 0;
        while (lft < nums.size() && nums[lft] == 0) {
            ++lft;
        }
        if (nums.size() <= lft) {
            return 0;
        }

        int rht = nums.size() - 1;
        while (lft < rht && nums[rht] == 0) {
            --rht;
        }
        if (lft == rht) {
            return 1;
        }

        long ret = 1;
        for (int pre = lft, cur = lft + 1; cur <= rht; ++cur) {
            if (nums[cur] == 0) {
                continue;
            }

            ret *= (cur - pre);
            ret %= M;

            pre = cur;
        }

        return ret;
    }
};
