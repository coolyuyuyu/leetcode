class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        // dp[num]: the length of the longest subsequence ending at num in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.
        unordered_map<int, int> dp;

        int ret = 0;
        for (int num : arr) {
            dp[num] = dp[num - difference] + 1;
            ret = std::max(ret, dp[num]);
        }

        return ret;
    }
};
