class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        assert(!nums.empty());

        const auto minmax = std::minmax_element(nums.begin(), nums.end());
        int diff = *(minmax.second) - *(minmax.first) - 2 * k;
        return diff <= 0 ? 0 : diff;
    }
};
