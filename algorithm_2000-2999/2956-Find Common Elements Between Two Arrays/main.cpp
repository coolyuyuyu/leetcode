class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());

        int ret1 = 0, ret2 = 0;
        for (int num : nums1) {
            if (s2.find(num) != s2.end()) {
                ++ret1;
            }
        }
        for (int num : nums2) {
            if (s1.find(num) != s1.end()) {
                ++ret2;
            }
        }
        return {ret1, ret2};
    }
};
