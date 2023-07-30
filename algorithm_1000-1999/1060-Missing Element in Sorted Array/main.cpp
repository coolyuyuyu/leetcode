class Solution {
public:
    // Time: O(N)
    int linearSearch(const vector<int>& nums, int k) {
        for (int num : nums) {
            if (num <= k) {
                ++k;
            }
            else {
                break;
            }
        }

        return k;
    }

    // Time: O(logN)
    int binarySearch(const vector<int>& nums, int k) {
        // S: [0, 1, 2, ..., mid-1], len(S): mid
        // T: number of nums less than mid

        int lo = 0, hi = nums.back() + (k - nums.front() + 1);
        while (lo < hi) {
            int mid = hi - (hi - lo) / 2;
            int s = mid;
            int t = std::distance(nums.begin(), std::lower_bound(nums.begin(), nums.end(), mid));
            if ((s - t) <= k) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }

        return lo;
    }

    int missingElement(vector<int>& nums, int k) {
        //return linearSearch(nums, nums.front() + k - 1);
        return binarySearch(nums, nums.front() + k - 1);
    }
};
