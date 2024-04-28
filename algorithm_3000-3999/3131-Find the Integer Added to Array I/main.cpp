class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int mn1 = *std::min_element(nums1.begin(), nums1.end());
        int mn2 = *std::min_element(nums2.begin(), nums2.end());
        return mn2 - mn1;
    }
};
