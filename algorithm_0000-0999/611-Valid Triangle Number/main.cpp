class Solution {
public:
    // Time: O(n^2 * logn)
    int bsearch(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1, lo = j + 1, hi = n; j < nums.size(); ++j, lo = std::max(lo, j + 1)) {
                lo = std::distance(nums.begin(), std::lower_bound(nums.begin() + lo, nums.begin() + hi, nums[i] + nums[j]));
                ret += (lo - j - 1);
            }
        }

        return ret;
    }

    // Time: O(n^2)
    int twopointer(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();

        int ret = 0;
        for (int k = n; 0 < k--;) {
            for (int i = 0, j = k - 1; i < j;) {
                if (nums[i] + nums[j] > nums[k]) {
                    ret += (j - i);
                    --j;
                }
                else {
                    ++i;
                }
            }
        }

        return ret;
    }

    int triangleNumber(vector<int>& nums) {
        //return bsearch(nums);
        return twopointer(nums);
    }
};
