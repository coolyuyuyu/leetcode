class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();

        std::sort(nums.begin(), nums.end());

        int ret = 1;

        long cnt = 0;
        for (int lft = 0, rht = 1; rht < n; ++rht) {
            cnt += 1L * (rht - lft) * (nums[rht] - nums[rht - 1]);
            while (cnt > k) {
                cnt -= (nums[rht] - nums[lft]);
                ++lft;
            }

            ret = std::max(ret, rht - lft + 1);
        }

        return ret;
    }
};
