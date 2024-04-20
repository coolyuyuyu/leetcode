class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        std::function<int(const vector<int>&)> f = [](const vector<int>& nums) {
            int n = nums.size();

            int ret = 0;
            for (int lft = 0; lft < n;) {
                int rht = lft + 1;
                while (rht < n && nums[rht - 1] < nums[rht]) {
                    ++rht;
                }
                ret = std::max(ret, rht - lft);

                lft = rht;
            }

            return ret;
        };

        int ret1 = f(nums);
        std::reverse(nums.begin(), nums.end());
        int ret2 = f(nums);
        return std::max(ret1, ret2);
    }
};
