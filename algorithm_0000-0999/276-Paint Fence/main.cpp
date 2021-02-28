class Solution {
public:
    int numWays(int n, int k) {
        if (n <= 0) {
            return 0;
        }
        else if (n == 1) {
            return k;
        }
        else if (n == 2) {
            return k * k;
        }
        else {
            int lastTwoDiffCount = k * (k - 1);
            int lastTwoSameCount = k;
            for (int i = 2; i < n; ++i) {
                int tmp = lastTwoDiffCount;
                lastTwoDiffCount = (lastTwoDiffCount + lastTwoSameCount) * (k - 1);
                lastTwoSameCount = tmp;
            }

            return lastTwoDiffCount + lastTwoSameCount;
        }
    }
};