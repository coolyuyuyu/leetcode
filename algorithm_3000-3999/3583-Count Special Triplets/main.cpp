class Solution {
public:
    int M = 1e9 + 7;

    int specialTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> m;

        int cntL[n];
        m.clear();
        for (int j = 0; j < n; ++j) {
            cntL[j] = m[nums[j] * 2];
            ++m[nums[j]];
        }

        int cntR[n];
        m.clear();
        for (int j = n - 1; j >= 0; --j) {
            cntR[j] = m[nums[j] * 2];
            ++m[nums[j]];
        }

        int ret = 0;
        for (int j = 0; j < n; ++j) {
            ret += (1L * cntL[j] * cntR[j]) % M;
            ret %= M;
        }

        return ret;
    }
};
