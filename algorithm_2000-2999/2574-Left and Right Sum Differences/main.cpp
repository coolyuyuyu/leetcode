class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        int total = 0;
        vector<int> presum(n);
        for (int i = 0; i < n; ++i) {
            total += nums[i];
            presum[i] = total;
        }

        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            int lftSum = presum[i] - nums[i], rhtSum = total - presum[i];
            ret[i] = abs(lftSum - rhtSum);
        }

        return ret;
    }
};
