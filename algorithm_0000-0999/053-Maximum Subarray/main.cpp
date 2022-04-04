class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        assert(!nums.empty());

        int ans = nums.front();
        int subAns = 0;
        for (int num : nums) {
            subAns += num;
            if (ans < subAns) {
                ans = subAns;
            }
            if (subAns < 0) {
                subAns = 0;
            }
        }

        return ans;
    }
};
