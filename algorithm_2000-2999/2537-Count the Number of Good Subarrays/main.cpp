class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> cnts;

        long long ret = 0;
        for (int i = 0, j = 0, n = nums.size(), cntPairs = 0; i < n; ++i) {
            for (; j < n && cntPairs < k; ++j) {
                cntPairs += cnts[nums[j]]++;
            }

            if (cntPairs >= k) {
                ret += n - j + 1;
            }

            cntPairs -= --cnts[nums[i]];
        }

        return ret;
    }
};
