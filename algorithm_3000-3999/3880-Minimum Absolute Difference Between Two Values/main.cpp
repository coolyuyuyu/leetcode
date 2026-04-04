class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int ret = INT_MAX;
        for (int x = 0, n = nums.size(), i = -1, j = -1; x < n; ++x) {
            if (nums[x] == 1) { i = x; }
            else if (nums[x] == 2) { j = x; };

            if (i >= 0 && j >= 0) {
                ret = std::min(ret, std::abs(i - j));
            }
        }

        return ret < INT_MAX ? ret : -1;
    }
};
