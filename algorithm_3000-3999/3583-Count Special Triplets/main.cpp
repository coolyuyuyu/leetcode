class Solution {
public:
    int M = 1e9 + 7;

    int specialTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> num2cnt;

        // cntI[j]: the number of valid i from nums[0:i-1] where nums[i] == nums[j] * 2
        int cntI[n];
        num2cnt.clear();
        for (int j = 0; j < n; ++j) {
            cntI[j] = num2cnt[nums[j] * 2];
            ++num2cnt[nums[j]];
        }

        // cntK[j]: the number of valid k from nums[i+1:] where nums[j] * 2 == nums[k]
        int cntK[n];
        num2cnt.clear();
        for (int j = n - 1; j >= 0; --j) {
            cntK[j] = num2cnt[nums[j] * 2];
            ++num2cnt[nums[j]];
        }

        int ret = 0;
        for (int j = 0; j < n; ++j) {
            ret += (1LL * cntI[j] * cntK[j]) % M;
            ret %= M;
        }

        return ret;
    }
};
