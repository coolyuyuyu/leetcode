class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int subAns = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                ++subAns;
                ans = max(ans, subAns);
            }
            else {
                subAns = 0;
            }
        }

        return ans;
    }
};