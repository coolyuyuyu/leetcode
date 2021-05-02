class Solution {
public:
    int twoSumLessThanK_BruteForce(vector<int>& nums, int k) {
        int sum = -1;
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = i + 1; j < nums.size(); ++j) {
                int s = nums[i] + nums[j];
                if (sum < s && s < k) {
                    sum = s;
                }
            }
        }

        return sum;
    }

    int twoSumLessThanK_Sort(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int sum = -1;

        for (size_t i = 0; i < nums.size(); ++i) {
            size_t j = lower_bound(nums.begin() + i + 1, nums.end(), k - nums[i]) - nums.begin() - 1;
            if (i < j) {
                sum = max(sum, nums[i] + nums[j]);
            }
        }

        return sum;
    }

    int twoSumLessThanK(vector<int>& nums, int k) {
        // Time: O(N^2)
        //return twoSumLessThanK_BruteForce(nums, k);

        // Time: O(NlogN)
        return twoSumLessThanK_Sort(nums, k);
    }
};
