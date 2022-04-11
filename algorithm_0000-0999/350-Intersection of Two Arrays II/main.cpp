class Solution {
public:
    // Time: O(MlogM + NlogN)
    vector<int> intersection_SearchSortedNonOverlapped(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        vector<int> nums;
        for (auto itr1 = nums1.begin(), itr2 = nums2.begin(); itr1 != nums1.end() && itr2 != nums2.end(); ++itr1) {
            itr2 = std::lower_bound(itr2, nums2.end(), *itr1);
            if (itr2 != nums2.end() && *itr2 == *itr1 ) {
                nums.push_back(*itr1);
                ++itr2;
            }
        }
        return nums;
    }

    // Time: O(MlogM + NlogN)
    vector<int> intersection_LinearOnSorted(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        vector<int> nums;
        for (auto itr1 = nums1.begin(), itr2 = nums2.begin(); itr1 != nums1.end() && itr2 != nums2.end();) {
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

    // Time: O(MlogM + NlogN)
    vector<int> intersection_StdLibrary(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        vector<int> nums(std::min(nums1.size(), nums2.size()));
        auto it = std::set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums.begin());
        nums.resize(it - nums.begin());
        return nums;
    }

    // Time: O((M + N)logN), Space: O(NlogN)
    vector<int> intersection_MapCount(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size()) {
            std::swap(nums1, nums2);
        }
        map<int, int> counts;
        for (int num : nums2) {
            ++counts[num];
        }

        vector<int> nums;
        for (int num : nums1) {
            auto itr = counts.find(num);
            if (itr != counts.end() && 0 < itr->second) {
                --(itr->second);
                nums.push_back(num);
            }
        }
        return nums;
    }

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //return intersection_SearchSortedNonOverlapped(nums1, nums2);
        //return intersection_LinearOnSorted(nums1, nums2);
        //return intersection_StdLibrary(nums1, nums2);

        return intersection_MapCount(nums1, nums2);
    }
};
