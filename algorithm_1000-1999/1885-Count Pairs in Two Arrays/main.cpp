class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        // nums1[i] + nums1[j] > nums2[i] + nums2[j]
        // => (nums1[i] - nums2[i]) + (nums1[j] - nums2[j]) > 0

        int n = nums1.size();

        int diffs[n];
        for (int i = 0; i < n; ++i) {
            diffs[i] = nums1[i] - nums2[i];
        }
        std::sort(diffs, diffs + n);

        long long ret = 0;
        for (int lft = 0, rht = n - 1; lft < n; ++lft) {
            while (rht >= 0 && diffs[lft] + diffs[rht] > 0) {
                --rht;
            }

            ret += n - std::max(lft, rht) - 1;
        }

        return ret;
    }
};
