class Solution {
public:
    vector<int> intersection_SearchSorted(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        vector<int> nums;
        for (size_t i = 0; i < nums1.size(); ++i) {
            if (0 < i && nums1[i] == nums1[i - 1]) {
                continue;
            }

            if (std::binary_search(nums2.begin(), nums2.end(), nums1[i])) {
                nums.push_back(nums1[i]);
            }
        }
        return nums;
    }

    vector<int> intersection_SearchSortedNonOverlapped(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        vector<int> nums;
        for (auto itr1 = nums1.begin(), itr2 = nums2.begin(); itr1 != nums1.end() && itr2 != nums2.end(); ++itr1) {
            if (itr1 != nums1.begin() && *itr1 == *(itr1 - 1)) {
                continue;
            }

            itr2 = std::lower_bound(itr2, nums2.end(), *itr1);
            if (itr2 != nums2.end() && *itr2 == *itr1 ) {
                nums.push_back(*itr1);
            }
        }
        return nums;
    }

    vector<int> intersection_LinearOnSorted(vector<int>& nums1, vector<int>& nums2) {
        std::set<int> set1(nums1.begin(), nums1.end());
        std::set<int> set2(nums2.begin(), nums2.end());

        vector<int> nums;
        for (auto itr1 = set1.begin(), itr2 = set2.begin(); itr1 != set1.end() && itr2 != set2.end();) {
            if (*itr1 < *itr2) {
                ++itr1;
            }
            else if (*itr1 == *itr2) {
                nums.push_back(*itr1);
                ++itr1;
                ++itr2;
            }
            else {
                ++itr2;
            }
        }
        return nums;
    }

    vector<int> intersection_StdLibrary(vector<int>& nums1, vector<int>& nums2) {
        std::set<int> set1(nums1.begin(), nums1.end());
        std::set<int> set2(nums2.begin(), nums2.end());

        vector<int> nums(std::min(nums1.size(), nums2.size()));
        auto it = std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), nums.begin());
        nums.resize(it - nums.begin());
        return nums;
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //return intersection_SearchSorted(nums1, nums2);
        return intersection_SearchSortedNonOverlapped(nums1, nums2);
        //return intersection_LinearOnSorted(nums1, nums2);
        //return intersection_StdLibrary(nums1, nums2);
    }
};
