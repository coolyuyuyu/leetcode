class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        int lftMax[n];
        lftMax[0] = INT_MIN;
        for (int i = 1; i < n; ++i) {
            lftMax[i] = std::max(lftMax[i - 1], nums[i - 1]);
        }

        int rhtMax[n];
        rhtMax[n - 1] = INT_MIN;
        for (int i = n - 2; i >= 0; --i) {
            rhtMax[i] = std::max(rhtMax[i + 1], nums[i + 1]);
        }

        long long ret = 0;
        for (int j = 1; j + 1 < n; ++j) {
            ret = std::max(ret, 1LL * (lftMax[j] - nums[j]) * rhtMax[j]);
        }

        return ret;
    }
};
