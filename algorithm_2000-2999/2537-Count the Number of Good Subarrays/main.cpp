class Solution {
public:
    // sliding window, Time: O(n)
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> cnts;
        long long numPairs = 0, ret = 0;
        for (int lft = 0, rht = 0; lft < n; ++lft) {
            for (; rht < n && numPairs < k; ++rht) {
                numPairs += cnts[nums[rht]]++;
            }
            if (k <= numPairs) {
                ret += (n - rht + 1);
            }

            numPairs -= --cnts[nums[lft]];
        }

        return ret;
    }
};
