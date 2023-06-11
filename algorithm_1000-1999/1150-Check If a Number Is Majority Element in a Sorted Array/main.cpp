class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        auto itr = std::lower_bound(nums.begin(), nums.end(), target);
        size_t count = std::distance(itr, std::upper_bound(itr, nums.end(), target));
        return nums.size() < (count * 2);
    }
};
