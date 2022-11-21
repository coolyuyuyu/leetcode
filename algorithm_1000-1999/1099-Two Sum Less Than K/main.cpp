class Solution {
public:
    // Time: O(n^2)
    int bruteforce(vector<int>& nums, int k) {
        int ans = -1;
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = i + 1; j < nums.size(); ++j) {
                int sum = nums[i] + nums[j];
                if (sum < k) {
                    ans = std::max(ans, sum);
                }
            }
        }

        return ans;
    }

    // Time: O(n^2)
    int linearScanSorted(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());

        int ans = -1;
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = i + 1; j < nums.size(); ++j) {
                int sum = nums[i] + nums[j];
                if (k <= sum) {
                    break;
                }
                ans = std::max(ans, sum);
            }
        }

        return ans;
    }

    // Time: O(nlogn)
    int binarySearchSorted(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());

        int ans = -1;
        for (size_t lft = 0, rht = nums.size(); lft < rht; ++lft) {
            if (0 < lft && nums[lft - 1] == nums[lft]) {
                continue;
            }

            size_t mid = std::lower_bound(nums.begin() + lft + 1, nums.begin() + rht, k - nums[lft]) - nums.begin();
            if ((lft + 1) < mid) {
                ans = std::max(ans, nums[lft] + nums[mid - 1]);
            }
            rht = mid;
        }

        return ans;
    }

    // Time: O(nlogn)
    int convergeSorted(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());

        int ans = -1;
        for (size_t lft = 0, rht = nums.size(); (lft + 1) < rht;) {
            int sum = nums[lft] + nums[rht - 1];
            if (sum < k) {
                ans = std::max(ans, sum);
                ++lft;
            }
            else {
                --rht;
            }
        }

        return ans;
    }

    int twoSumLessThanK(vector<int>& nums, int k) {
        //return bruteforce(nums, k);
        //return linearScanSorted(nums, k);
        //return binarySearchSorted(nums, k);
        return convergeSorted(nums, k);
    }
};
