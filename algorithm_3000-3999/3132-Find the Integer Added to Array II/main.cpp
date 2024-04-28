class Solution {
public:
    bool check(vector<int>& arr1, vector<int>& arr2, int maxSkip) {
        int m = arr1.size();
        int n = arr2.size();
        int skip = 0;
        for (int i = 0, j = 0; i < m && j < n; ++j) {
            while (i < m && arr1[i] != arr2[j]) {
                ++i;
                ++skip;
            }
            ++i;
        }

        return skip <= maxSkip;
    }

    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        int n = nums2.size();
        vector<int> arr2;
        for (int i = 0; i < n; ++i) {
            arr2.push_back(nums2[i] - nums2[0]);
        }

        int ret = INT_MAX;
        vector<int> arr1;

        arr1.clear();
        for (int i = 0; i < nums1.size(); ++i) {
            arr1.push_back(nums1[i] - nums1[0]);
        }
        if (check(arr1, arr2, 2)) {
            ret = std::min(ret, nums2[0] - nums1[0]);
        }

        arr1.clear();
        for (int i = 1; i < nums1.size(); ++i) {
            arr1.push_back(nums1[i] - nums1[1]);
        }
        if (check(arr1, arr2, 1)) {
            ret = std::min(ret, nums2[0] - nums1[1]);
        }

        arr1.clear();
        for (int i = 2; i < nums1.size(); ++i) {
            arr1.push_back(nums1[i] - nums1[2]);
        }
        if (check(arr1, arr2, 0)) {
            ret = std::min(ret, nums2[0] - nums1[2]);
        }

        return ret;
    }
};
