class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();

        vector<bool> ret(n);
        for (int i = 0, sum = 0; i < n; ++i) {
            sum = sum * 2 + nums[i];
            sum %= 5;
            ret[i] = (sum == 0);
        }

        return ret;
    }
};
