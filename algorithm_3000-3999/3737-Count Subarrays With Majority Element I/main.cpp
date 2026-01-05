class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = i; j < n; ++j) {
                cnt += (nums[j] == target ? 1 : 0);
                if (cnt * 2 > (j - i + 1)) {
                    ret += 1;
                }
            }
        }

        return ret;
    }
};
