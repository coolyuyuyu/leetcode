class Solution {
public:
    // Time: O(MlogM + NlogN)
    vector<int> byBinarySearchSorted(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        vector<int> ret;
        for (auto itr1 = nums1.begin(), itr2 = nums2.begin(); itr1 != nums1.end() && itr2 != nums2.end(); ++itr1) {
            itr2 = std::lower_bound(itr2, nums2.end(), *itr1);
            if (itr2 != nums2.end() && *itr1 == *itr2) {
                ret.push_back(*itr2++);
            }
        }

        return ret;
    }

    // Time: O(MlogM + NlogN)
    vector<int> byLinearSearchSorted(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        vector<int> ret;
        for (auto itr1 = nums1.begin(), itr2 = nums2.begin(); itr1 != nums1.end() && itr2 != nums2.end();) {
            if (*itr1 < *itr2) {
                ++itr1;
            }
            else if (*itr1 == *itr2) {
                ret.push_back(*itr1);
                ++itr1, ++itr2;
            }
            else {
                ++itr2;
            }
        }

        return ret;
    }

    // Time: O(MlogM + NlogN)
    vector<int> byStdLib(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        vector<int> ret;
        std::set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(ret));

        return ret;
    }

    // Time: O(M + N), Space: O(N)
    vector<int> byHashCount(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> cnts2;
        for (int num2 : nums2) {
            ++cnts2[num2];
        }

        vector<int> ret;
        for (int num1 : nums1) {
            auto itr2 = cnts2.find(num1);
            if (itr2 != cnts2.end() && itr2->second > 0) {
                --itr2->second;
                ret.push_back(num1);
            }
        }

        return ret;
    }

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //return byBinarySearchSorted(nums1, nums2);
        //return byLinearSearchSorted(nums1, nums2);
        //return byStdLib(nums1, nums2);
        return byHashCount(nums1, nums2);
    }
};
