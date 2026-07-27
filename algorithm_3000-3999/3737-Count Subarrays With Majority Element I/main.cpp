class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ret = 0;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            int cnt = 0;
            for (int j = i; j < n; ++j) {
                cnt += (nums[j] == target);
                if (cnt * 2 > j - i + 1) {
                    ++ret;
                }
            }
        }

        return ret;
    }
};
