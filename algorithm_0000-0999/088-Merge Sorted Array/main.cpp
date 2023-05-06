class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m + n; 0 < m && 0 < n; --i) {
            if (nums1[m - 1] <= nums2[n - 1]) {
                nums1[i - 1] = nums2[--n];
            }
            else {
                nums1[i - 1] = nums1[--m];
            }
        }
        std::copy(nums2.begin(), nums2.begin() + n, nums1.begin());
    }
};
