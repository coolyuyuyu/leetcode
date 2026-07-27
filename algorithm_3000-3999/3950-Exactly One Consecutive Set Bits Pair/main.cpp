class Solution {
public:
    bool consecutiveSetBits(int n) {
        int cnt = 0; 
        for (bool preSet = false; n; n >>= 1) {
            int curSet = n & 1;
            if (preSet && curSet) {
                if (++cnt >= 2) {
                    return false;
                }
            }
            preSet = curSet;
        }

        return cnt == 1;
    }
};
