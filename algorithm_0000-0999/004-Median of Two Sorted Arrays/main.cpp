class Solution {
public:
    double binarySearch(vector<int>& nums1, vector<int>& nums2) {
        std::function<int(size_t, size_t, size_t, size_t, size_t)> findKth = [&](size_t lo1, size_t hi1, size_t lo2, size_t hi2, size_t k) {
            if (lo1 >= hi1) {
                return nums2[lo2 + k];
            }
            else if (lo2 >= hi2) {
                return nums1[lo1 + k];
            }

            size_t halfLen1 = (hi1 - lo1) / 2, halfLen2 = (hi2 - lo2) / 2;
            if (halfLen1 + halfLen2 < k) {
                if (nums1[lo1 + halfLen1] < nums2[lo2 + halfLen2]) {
                    return findKth(lo1 + halfLen1 + 1, hi1, lo2, hi2, k - halfLen1 - 1);
                }
                else {
                    return findKth(lo1, hi1, lo2 + halfLen2 + 1, hi2, k - halfLen2 - 1);
                }
            }
            else {
                if (nums1[lo1 + halfLen1] < nums2[lo2 + halfLen2]) {
                    return findKth(lo1, hi1, lo2, lo2 + halfLen2, k);
                }
                else {
                    return findKth(lo1, lo1 + halfLen1, lo2, hi2, k);
                }
            }
        };

        size_t len1 = nums1.size(), len2 = nums2.size();
        size_t len = len1 + len2;
        double ret = findKth(0, len1, 0, len2, len / 2);
        if (len % 2 == 0) {
            ret += findKth(0, len1, 0, len2, len / 2 - 1);
            ret /= 2.0;
        }

        return ret;
    }

    double linearScan(vector<int>& nums1, vector<int>& nums2) {
        std::function<int(size_t)> findKth = [&](size_t k) {
            size_t i = 0, j = 0;
            size_t len1 = nums1.size(), len2 = nums2.size();
            while (i < len1 && j < len2 && i + j < k) {
                if (nums1[i] < nums2[j]) {
                    ++i;
                }
                else {
                    ++j;
                }
            }

            if (i == len1) {
                return nums2[k - len1];
            }
            else if (j == len2) {
                return nums1[k - len2];
            }
            else {
                return std::min(nums1[i], nums2[j]);
            }
        };

        size_t len1 = nums1.size(), len2 = nums2.size();
        size_t len = len1 + len2;
        double ret = findKth(len / 2);
        if (len % 2 == 0) {
            ret += findKth(len / 2 - 1);
            ret /= 2.0;
        }

        return ret;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //return binarySearch(nums1, nums2);
        return linearScan(nums1, nums2);
    }
};
