class Solution {
public:
    int finalElement(vector<int>& nums) {
        assert(!nums.empty());

        if (nums.size() == 1) {
            return nums[0];
        }
        else {
            return std::max(nums.front(), nums.back());
        }
    }
};
