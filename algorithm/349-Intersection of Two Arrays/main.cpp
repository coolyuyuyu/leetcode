class Solution {
public:
    vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());

        vector<int> result(min(nums1.size(), nums2.size()));
        vector<int>::iterator it = set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), result.begin());
        result.resize(it - result.begin());
        return result;
    }

    int search(const vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }

        size_t lo = 0;
        size_t hi = nums.size() - 1;
        while (lo <= hi) {
            size_t mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (target < nums[mid]) {
                if (mid == 0) {
                    return -1;
                }
                hi = mid - 1;
            }
            else {
                assert(nums[mid] < target);
                lo = mid + 1;
            }
        }

        return -1;
    }

    vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> ans;

        sort(nums2.begin(), nums2.end());
        for (int num : nums1) {
            if (ans.find(num) == ans.end() && 0 <= search(nums2, num)) {
                ans.insert(num);
            }
        }

        return vector<int>(ans.begin(), ans.end());
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //return intersection1(nums1, nums2);

        return intersection2(nums1, nums2);
    }
};