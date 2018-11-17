class Solution {
public:
    int binaryGap(int N) {
        int maxGap = 0;
        for (int lastIndex = -1, i = 0; i < 32; ++i, N >>= 1) {
            if (N & 1) {
                if (lastIndex >= 0) {
                    int gap = i - lastIndex;
                    if (maxGap < gap) {
                        maxGap = gap;
                    }
                }
                lastIndex = i;
            }
        }

        return maxGap;
    }
};