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

        int ret = -1;
        for (int i = 0; i < nums.size(); ++i) {
            int j = std::distance(nums.begin(), std::lower_bound(nums.begin() + i + 1, nums.end(), k - nums[i])) - 1;
            if (i < j) {
                ret = std::max(ret, nums[i] + nums[j]);
            }
        }

        return ret;
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
        return binarySearchSorted(nums, k);
        //return convergeSorted(nums, k);
    }
};