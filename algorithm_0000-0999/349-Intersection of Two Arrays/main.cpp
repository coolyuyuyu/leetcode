class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> ret;
        for (int i = 0, j = 0; i < m && j < n;) {
            if (i > 0 && nums1[i - 1] == nums1[i]) {
                ++i;
            }
            else if (j > 0 && nums2[j - 1] == nums2[j]) {
                ++j;
            }
            else if (nums1[i] < nums2[j]) {
                ++i;
            }
            else if (nums1[i] == nums2[j]) {
                ret.push_back(nums1[i]);
                ++i, ++j;
            }
            else {
                ++j;
            }
        }

        return ret;
    }
};
