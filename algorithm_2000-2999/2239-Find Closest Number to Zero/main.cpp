class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        assert(!nums.empty());

        int ans = nums.front();
        for (size_t i = 1; i < nums.size(); ++i) {
            int diff = abs(nums[i]) - abs(ans);
            if (diff < 0) {
                ans = nums[i];
            }
            else if (diff == 0) {
                ans = std::max(ans, nums[i]);
            }
        }

        return ans;
    }
};
