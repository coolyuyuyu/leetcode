class Solution {
public:
    int minOperations(string s) {
        // dp0[i]: the minimum number of operations to make s[0:i] alternating and ending with '0'
        // dp1[i]: the minimum number of operations to make s[0:i] alternating and ending with '1'
        int dp0 = 0, dp1 = 0;
        for (char c : s) {
            int tmp0 = dp0, tmp1 = dp1;
            dp0 = tmp1 + (c == '0' ? 0 : 1);
            dp1 = tmp0 + (c == '1' ? 0 : 1);
        }

        return std::min(dp0, dp1);
    }
};
