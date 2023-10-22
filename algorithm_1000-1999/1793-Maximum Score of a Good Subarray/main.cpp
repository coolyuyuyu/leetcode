class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();

        int ret = 0;
        for (int l = k, r = k, minVal = nums[k]; 0 <= l || r < n; minVal = std::max((0 <= l ? nums[l] : 0), (r < n ? nums[r] : 0))) {
            while (0 <= l && nums[l] >= minVal) { --l; }
            while (r < n && nums[r] >= minVal) { ++r; }

            ret = std::max(ret, minVal * (r - l - 1));
        }

        return ret;
    }
};
