class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        auto itrLo = std::lower_bound(nums.begin(), nums.end(), target);
        auto itrHi = std::upper_bound(itrLo, nums.end(), target);
        int count = std::distance(itrLo, itrHi);
        return nums.size() < (count * 2);
    }
};
