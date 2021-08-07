class Solution {
public:
    vector<int> shuffle_NaiveBruteForce(vector<int>& nums, int n) {
        vector<int> ans(2 * n);
        for (int i = 0; i < n; ++i) {
            ans[2 * i + 0] = nums[i];
            ans[2 * i + 1] = nums[n + i];
        }

        return ans;
    }

    vector<int> shuffle_OptimizedBruteForce(vector<int>& nums, int n) {
        for (int i = 0; i < n; ++i) {
            nums[i] += nums[n + i] * 10000;
        }

        for (int i = n - 1; 0 <= i ; --i) {
            nums[2 * i + 1] = nums[i] / 10000;
            nums[2 * i + 0] = nums[i] % 10000;
        }

        return nums;
    }

    vector<int> shuffle(vector<int>& nums, int n) {
        // Time: O(N), Space: O(N)
        // return shuffle_NaiveBruteForce(nums, n);

        // Time: O(N), Space: O(1)
        return shuffle_OptimizedBruteForce(nums, n);
    }
};
