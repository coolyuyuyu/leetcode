class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        for (int lft = 0, rht = 0; rht < n;) {
            int cnt = __builtin_popcount(nums[lft]);
            while (rht < n && __builtin_popcount(nums[rht]) == cnt) {
                ++rht;
            }

            std::sort(nums.begin() + lft, nums.begin() + rht);
            if (lft > 0 && nums[lft - 1] > nums[lft]) {
                return false;
            }

            lft = rht;
        }

        return true;
    }
};
