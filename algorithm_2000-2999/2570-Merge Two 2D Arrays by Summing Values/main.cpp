class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ret;

        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i][0] < nums2[j][0]) {
                ret.push_back(nums1[i]);
                ++i;
            }
            else if (nums1[i][0] == nums2[j][0]) {
                ret.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                ++i, ++j;
            }
            else {
                ret.push_back(nums2[j]);
                ++j;
            }
        }
        ret.insert(ret.end(), nums1.begin() + i, nums1.end());
        ret.insert(ret.end(), nums2.begin() + j, nums2.end());

        return ret;
    }
};
