class Solution {
public:
    // Time: O(N), Space: O(1)
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        int dup;
        int x = n * (n + 1) / 2; // 1 + 2 + ... + n
        int y = 0; // sum of nums
        for (int i = 0; i < n; ++i) {
            int val = abs(nums[i]);
            if (0 < nums[val - 1]) {
                nums[val - 1] = -nums[val - 1];
            }
            else {
                dup = val;
            }

            y += val;
        }

        return {dup, dup + x - y};
    }
};
