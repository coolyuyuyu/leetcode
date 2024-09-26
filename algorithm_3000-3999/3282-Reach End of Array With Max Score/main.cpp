class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();

        long long ret = 0;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[cur] < nums[i]) {
                ret += 1LL * (i - cur) * nums[cur];
                cur = i;
            }
        }
        ret += 1LL * (n - 1 - cur) * nums[cur];

        return ret;
    }
};
