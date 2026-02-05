class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                ret[i] = nums[(i + nums[i]) % n];
            }
            else if (nums[i] < 0) {
                ret[i] = nums[((i + nums[i]) % n + n) % n];
            }
            else {
                ret[i] = 0;
            }
        }

        return ret;
    }
};
