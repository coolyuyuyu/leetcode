class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size();

        int total = 0;
        vector<int> presum(n);
        for (int i = 0; i < n; ++i) {
            total += nums[i];
            presum[i] = total;
        }

        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            ret[i] = abs(presum[i] - nums[i] - (total - presum[i]));
        }

        return ret;
    }
};
