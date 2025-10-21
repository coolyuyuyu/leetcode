class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        if (std::count(nums.begin(), nums.end(), 0) == n) {
            return 0;
        }

        int sum = 0;
        for (int num : nums) {
            sum ^= num;
        }

        return sum != 0 ? n : (n - 1);
    }
};
