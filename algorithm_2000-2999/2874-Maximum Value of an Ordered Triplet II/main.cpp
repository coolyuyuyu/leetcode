class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        int rhtMax[n];
        rhtMax[n - 1] = INT_MIN;
        for (int i = n - 2; 0 <= i; --i) {
            rhtMax[i] = std::max(rhtMax[i + 1], nums[i + 1]);
        }

        long long ret = LLONG_MIN;
        for (int j = 1, lftMax = nums[0]; (j + 1) < n; ++j) {
            ret = std::max(ret, (long long)(lftMax - nums[j]) * rhtMax[j]);
            lftMax = std::max(lftMax, nums[j]);
        }

        return std::max(ret, 0LL);
    }
};
