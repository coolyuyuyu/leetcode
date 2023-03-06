class Solution {
public:
    // O(n)
    int linear(const vector<int>& nums, int k) {
        for (int num : nums) {
            if (num <= k) {
                ++k;
            }
            else {
                return k;
            }
        }

        return k;
    }

    // O(logn)
    int bsearch(const vector<int>& arr, int k) {
        // lft, ...., mid, ..., rht
        // S: [1, 2, ..., mid-1]
        // T: [all arr elements which is less then mid]
        // if mid == kth missing element
        //     => len(S) - len(T) = k - 1

        int lft = 1, rht = arr.back() + k;
        while (lft < rht) {
            int mid = rht - (rht - lft) / 2;
            int s = mid - 1;
            int t = std::distance(arr.begin(), std::lower_bound(arr.begin(), arr.end(), mid));
            if ((s - t) <= (k - 1)) {
                lft = mid;
            }
            else {
                rht = mid - 1;
            }
        }

        return lft;
    }

    int missingElement(vector<int>& nums, int k) {
        return linear(nums, nums.front() + k - 1);
        //return linear(nums, nums.front() + k - 1);
    }
};
