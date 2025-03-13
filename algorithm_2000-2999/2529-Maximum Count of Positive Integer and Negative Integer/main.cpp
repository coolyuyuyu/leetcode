class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int cntN = std::distance(nums.begin(), std::lower_bound(nums.begin(), nums.end(), 0));
        int cntP = std::distance(std::upper_bound(nums.begin(), nums.end(), 0), nums.end());
        return std::max(cntN, cntP);
    }
};
