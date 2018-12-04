class Solution {
public:
    // Runtime preferable when nums1's size is small compared to nums2's size
    vector<int> intersect1(const vector<int>& nums1, const vector<int>& nums2) {
        unordered_map<int, int> counts2;
        for (int num2 : nums2) {
            ++counts2[num2];
        }

        vector<int> ans;
        for (int num1 : nums1) {
            if (counts2[num1] > 0) {
                --counts2[num1];
                ans.push_back(num1);
            }
        }

        return ans;
    }

    // Space preferable when nums1's size is small compared to nums2's size
    vector<int> intersect2(const vector<int>& nums1, const vector<int>& nums2) {
        unordered_map<int, int> counts1;
        for (int num1 : nums1) {
            ++counts1[num1];
        }

        vector<int> ans;
        for (int num2 : nums2) {
            if (counts1[num2] > 0) {
                --counts1[num2];
                ans.push_back(num2);
            }
        }

        return ans;
    }

    size_t searchInsert(const vector<int>& nums, int target) {
        size_t lo = 0;
        size_t hi = nums.size();
        while (lo < hi) {
            size_t mid = lo + (hi - lo) / 2;
            if (target <= nums[mid]) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        assert(lo == hi);
        return lo;
    }

    size_t count(const vector<int>& nums, int target) {
        size_t lo = searchInsert(nums, target);
        if (nums.size() <= lo || nums[lo] != target) {
            return 0;
        }
        return searchInsert(nums, target + 1) - lo;
    }

    // Preferable when nums1 and nums2 are SORTED, time: m + n
    vector<int> intersect3(const vector<int>& nums1, const vector<int>& nums2) {
        vector<int> ans;

        auto itr1 = nums1.begin(), itr2 = nums2.begin();
        for (auto itr1 = nums1.begin(), itr2 = nums2.begin(); itr1 != nums1.end() && itr2 != nums2.end();) {
            if (*itr1 < *itr2) {
                ++itr1;
            }
            else if (*itr1 > *itr2) {
                ++itr2;
            }
            else {
                ans.push_back(*itr1);
                ++itr1;
                ++itr2;
            }
        }

        return ans;
    }

    // Preferable when nums1 and nums2 are SORTED, STL algorthm, time: up to (m + n) in general
    vector<int> intersect4(const vector<int>& nums1, const vector<int>& nums2) {
        vector<int> result(min(nums1.size(), nums2.size()));
        vector<int>::iterator it = set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), result.begin());
        result.resize(it - result.begin());
        return result;
    }

    // Preferable when nums1 and nums2 are SORTED, time: m + log(n)
    vector<int> intersect5(const vector<int>& nums1, const vector<int>& nums2) {
        vector<int> ans;

        size_t preIndex = 0;
        for (size_t index = 0; index < nums1.size(); ++index) {
            if (nums1.size() <= (index + 1) || nums1[index] != nums1[index + 1]) {
                int num1 = nums1[index];
                int intersectCount = min(index - preIndex + 1, count(nums2, num1));
                while (intersectCount--) {
                    ans.push_back(num1);
                }

                preIndex = index + 1;
            }
        }

        return ans;
    }

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //return intersect1(nums1, nums2);

        //return intersect2(nums1, nums2);

        //sort(nums1.begin(), nums1.end());
        //sort(nums2.begin(), nums2.end());
        //return intersect3(nums1, nums2);

        //sort(nums1.begin(), nums1.end());
        //sort(nums2.begin(), nums2.end());
        //return intersect4(nums1, nums2);

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        return intersect5(nums1, nums2);
    }
};