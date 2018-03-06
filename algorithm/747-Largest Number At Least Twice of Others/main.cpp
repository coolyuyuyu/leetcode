class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        assert(!nums.empty());

        size_t index = 0;
        int numFirst = numeric_limits<int>::min();
        int numSecond = numeric_limits<int>::min();
        for (size_t i = 0; i < nums.size(); ++i) {
            if (numFirst < nums[i]) {
                numSecond = numFirst;
                numFirst = nums[i];
                index = i;
            }
            else if (numSecond < nums[i]) {
                numSecond = nums[i];
            }
        }

        return (numSecond * 2 <= numFirst) ? index : -1;
    }
};