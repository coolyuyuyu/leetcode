class Solution {
public:
    // Time: O(32)
    int f1(int start, int goal) {
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

    // Time: O(1)
    int f2(int start, int goal) {
        return __builtin_popcount(start ^ goal);
    }

    int minBitFlips(int start, int goal) {
        //return f1(start, goal);
        return f2(start, goal);
    }
};
