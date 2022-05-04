class Solution {
public:
    // Time: O(N), Space: O(N)
    int iterative_dp1(int n) {
        if (n < 2) {
            return 1;
        }

        vector<int> cnts(n + 1);
        cnts[0] = cnts[1] = 1;
        for (size_t i = 2; i < cnts.size(); ++i) {
            cnts[i] = cnts[i - 1] + cnts[i - 2];
        }

        return cnts.back();
    }

    // Time: O(N), Space: O(1)
    int iterative_dp2(int n) {
        if (n < 2) {
            return 1;
        }

        int x = 1, y = 1;
        for (size_t i = 2; i <= n; ++i) {
            int tmp = x + y;
            y = x;
            x = tmp;
        }

        return x;
    }

    int climbStairs(int n) {
        //return iterative_dp1(n);
        return iterative_dp2(n);
    }
};
