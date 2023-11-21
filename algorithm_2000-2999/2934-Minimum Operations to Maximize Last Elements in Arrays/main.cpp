class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        int ret1 = 0;
        for (int i = 0; i + 1 < n; ++i) {
            if (nums1[i] <= nums1.back() && nums2[i] <= nums2.back()) {
            }
            else if (nums1[i] <= nums2.back() && nums2[i] <= nums1.back()) {
                ++ret1;
            }
            else {
                ret1 = -1;
                break;
            }
        }

        int ret2 = 1;
        std::swap(nums1.back(), nums2.back());
        for (int i = 0; i + 1 < n; ++i) {
            if (nums1[i] <= nums1.back() && nums2[i] <= nums2.back()) {
            }
            else if (nums1[i] <= nums2.back() && nums2[i] <= nums1.back()) {
                ++ret2;
            }
            else {
                ret2 = -1;
                break;
            }
        }

        return std::min(ret1, ret2);
    }
};
