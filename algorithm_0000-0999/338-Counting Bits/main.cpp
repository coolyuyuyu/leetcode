class Solution {
public:
    vector<int> dp1(int n) {
        /*
        0:  0
        1:  1
        2: 10
        3: 11
        4:100
        5:101
        6:110
        7:111
        */
        vector<int> dp(n + 1, 0);
        for (int i = 0; i <= n; ++i) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }

    vector<int> dp2(int n) {
        /*
        0:  0
        -----
        1:  1
        -----
        2: 10
        3: 11
        -----
        4:100
        5:101
        6:110
        7:111
        */
        vector<int> dp = {0};
        while (dp.size() < (n + 1)) {
            for (size_t lo = 0,  hi = dp.size(); lo < hi && dp.size() < (n + 1); ++lo) {
                dp.push_back(dp[lo] + 1);
            }
        }

        return dp;
    }

    vector<int> countBits(int n) {
        //return dp1(n);
        return dp2(n);
    }
};
