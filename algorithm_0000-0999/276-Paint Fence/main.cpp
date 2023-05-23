class Solution {
public:
    int numWays(int n, int k) {
        if (n == 1) {
            return k;
        }

        int diff = k * (k - 1); // diff[i]: the number of ways to paint posts[0:i] and colors[i-1] != colors[i]
        int same = k;           // same[i]: the number of ways to paint posts[0:i] and colors[i-1] == colors[i]
        for (int i = 2; i < n; ++i) {
            int tmpDiff = diff, tmpSame = same;
            diff = tmpDiff * (k - 1) + tmpSame * (k - 1);
            same = tmpDiff;
        }

        return diff + same;
    }
};
