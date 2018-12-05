class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        assert(!nums.empty());

        int ans = nums.front();
        int subAns = 0;
        for (int num : nums) {
            subAns += num;
            ans = max(ans, subAns);
            subAns = max(subAns, 0);
        }

        return ans;
    }
};