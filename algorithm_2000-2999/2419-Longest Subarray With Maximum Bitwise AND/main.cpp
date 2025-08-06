class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int target = *std::max_element(nums.begin(), nums.end());

        int ret = 0, cnt = 0;
        for (int num : nums) {
            if (num == target) {
                ++cnt;
                ret = std::max(ret, cnt);
            }
            else {
                cnt = 0;
            }
        }

        return ret;
    }
};
