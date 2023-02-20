class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        // sorted:
        //     X X X X X X X X
        // 1.  ^         ^         change last 2 to nums[n-3]
        // 2.      ^         ^     change first 2 to nums[2]
        // 3.    ^         ^       change first to nums[1] and last to nums[n-2]

        sort(nums.begin(), nums.end());

        int n = nums.size();
        return std::min({
            nums[n - 3] - nums[0],
            nums[n - 1] - nums[2],
            nums[n - 2] - nums[1],
        });
    }
};
