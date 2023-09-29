class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        auto itr = std::find_if(nums.begin(), nums.end(), [&](int num) { return num != nums[0]; });
        if (itr != nums.end() && nums[0] < *itr) {
            return std::is_sorted(itr, nums.end(), std::less<int>());
        }
        else {
            return std::is_sorted(itr, nums.end(), std::greater<int>());
        }
    }
};
