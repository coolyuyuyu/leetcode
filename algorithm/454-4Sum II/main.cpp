class Solution {
public:
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

    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        vector<int> nums1;
        nums1.reserve(A.size() * B.size());
        for (int numA : A) {
            for (int numB : B) {
                nums1.push_back(numA + numB);
            }
        }

        vector<int> nums2;
        nums2.reserve(C.size() * D.size());
        for (int numC : C) {
            for (int numD : D) {
                nums2.push_back(numC + numD);
            }
        }

        sort(nums2.begin(), nums2.end());

        int ans = 0;
        for (int num1 : nums1) {
            int num2 = -num1;
            size_t lo = searchInsert(nums2, num2);
            if (nums2.size() <= lo || nums2[lo] != num2) {
                continue;
            }
            size_t hi = searchInsert(nums2, num2 + 1);

            ans += (hi - lo);
        }

        return ans;
    }
};