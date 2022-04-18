class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        assert(!nums.empty());

        // Assume sorted: ..., max2, max1;
        int max1 = nums.front();
        int max2 = INT_MIN;
        size_t index = 0;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (max1 <= nums[i]) {
                max2 = max1;
                max1 = nums[i];
                index = i;
            }
            else if (max2 < nums[i]) {
                max2 = nums[i];
            }
        }

        return (max2) <= (max1 / 2) ? index : -1;
    }
};