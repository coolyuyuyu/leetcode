class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ret = 0;
        for (int i = 0; i < 31; ++i) {
            if ((start & 1) != (goal & 1)) {
                ++ret;
            }
            start >>= 1;
            goal >>= 1;
        }

        return ret;
    }
};
