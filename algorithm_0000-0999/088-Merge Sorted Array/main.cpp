class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n - 1;
        --m;
        --n;
        while (0 <= m && 0 <= n) {
            if (nums1[m] <= nums2[n]) {
                nums1[index] = nums2[n];
                --n;
            }
            else {
                nums1[index] = nums1[m];
                --m;
            }
            --index;
        }

        if (0 <= n) {
            copy(nums2.begin(), nums2.begin() + n + 1, nums1.begin());
        }
    }
};