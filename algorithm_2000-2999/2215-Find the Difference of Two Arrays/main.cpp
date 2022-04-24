class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        vector<vector<int>> ans(2);

        size_t i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if ((i + 1) < nums1.size() && nums1[i] == nums1[i + 1]) {
                ++i;
                continue;
            }
            if ((j + 1) < nums2.size() && nums2[j] == nums2[j + 1]) {
                ++j;
                continue;
            }

            int diff = nums1[i] - nums2[j];
            if (diff == 0) {
                ++i;
                ++j;
            }
            else if (diff < 0) {
                ans[0].push_back(nums1[i++]);
            }
            else {
                ans[1].push_back(nums2[j++]);
            }
        }
        for (; i < nums1.size(); ++i) {
            if ((i + 1) < nums1.size() && nums1[i] == nums1[i + 1]) {
                continue;
            }
            ans[0].push_back(nums1[i]);
        }
        for (; j < nums2.size(); ++j) {
            if ((j + 1) < nums2.size() && nums2[j] == nums2[j + 1]) {
                continue;
            }
            ans[1].push_back(nums2[j]);
        }

        return ans;
    }
};
