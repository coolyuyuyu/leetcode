class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        int ret = 0;
        for (int i = 0, n = nums1.size(); i < n; ++i) {
            ret += nums1[i] * nums2[n - i - 1];
        }

        return ret;
    }
};
