class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        std::sort(nums.begin(), nums.end());

        long long ret = 0;
        for (int i = 0, lft = n - 1, rht = n - 1; i < n; ++i) {
            while (0 <= rht && upper < (nums[i] + nums[rht])) { --rht; }
            while (0 <= lft && lower <= (nums[lft] + nums[i])) { --lft; }
            int cnt = rht - lft;
            if (lft < i && i <= rht) {
                cnt -= 1;
            }
            ret += cnt;
        }

        return ret / 2;
    }
};

// lower <= nums[i] + x <= upper
// => lower - nums[i] <= x <= upper - nums[i]
// => x in [lower-nums[i], upper - nums[i]]
