class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        double ret = DBL_MAX;
        for (int lft = 0, rht = nums.size() - 1; lft < rht; ++lft, --rht) {
            ret = std::min(ret, (nums[lft] + nums[rht]) * 0.5);
        }

        return ret;
    }
};
