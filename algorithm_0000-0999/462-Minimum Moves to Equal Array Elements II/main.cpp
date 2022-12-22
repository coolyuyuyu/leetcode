class Solution {
public:
    int minMoves2(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];

        int ret = 0;
        for (int num : nums) {
            ret += abs(num - median);
        }

        return ret;
    }
};
