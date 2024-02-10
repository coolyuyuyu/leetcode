class Solution {
public:
    int numWays(int n, int k) {
        // same[i]: number of ways to paint posts[1:i], and colors[i-1] == colors[i]
        int same = 0;
        // diff[i]: number of ways to paint posts[1:i], and colors[i-1] != colors[i]
        int diff = k;
        for (int i = 2; i <= n; ++i) {
            int sameTmp = same, diffTmp = diff;
            same = diffTmp;
            diff = (sameTmp + diffTmp) * (k - 1);
        }

        return same + diff;
    }
};
