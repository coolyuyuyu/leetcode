class Solution {
public:
    int findKth(const vector<int>& nums1, size_t l1, size_t h1,  const vector<int>& nums2, size_t l2, size_t h2, size_t k) {
        if (h1 <= l1) {
            return nums2[l2 + k];
        }
        if (h2 <= l2) {
            return nums1[l1 + k];
        }

        size_t n1 = h1 - l1, n2 = h2 - l2;
        size_t halfCnt1 = n1 / 2, halfCnt2 = n2 / 2;
        int m1 = nums1[l1 + halfCnt1], m2 = nums2[l2 + halfCnt2];
        if ((halfCnt1 + halfCnt2) < k) {
            if (m2 < m1) {
                return findKth(nums1, l1, h1, nums2, l2 + halfCnt2 + 1, h2, k - halfCnt2 - 1);
            }
            else {
                return findKth(nums1, l1 + halfCnt1 + 1, h1, nums2, l2, h2, k - halfCnt1 - 1);
            }
        }
        else {
            if (m2 < m1) {
                return findKth(nums1, l1, l1 + halfCnt1, nums2, l2, h2, k);
            }
            else {
                return findKth(nums1, l1, h1, nums2, l2, l2 + halfCnt2, k);
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t n = nums1.size() + nums2.size();
        double m = findKth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), n / 2);
        if (n % 2 == 1) {
            return m;
        }
        else {
            m += findKth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), n / 2 - 1);
            m /= 2.0;
        }

        return m;
    }
};
