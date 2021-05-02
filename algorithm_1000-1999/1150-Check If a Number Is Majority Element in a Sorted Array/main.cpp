class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        auto itr = lower_bound(nums.begin(), nums.end(), target);
        if (itr == nums.end()) {
            return false;
        }

        size_t count = lower_bound(nums.begin(), nums.end(), target + 1) - itr;
        return ((nums.size() / 2) < count);
    }
};
