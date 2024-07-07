class Solution {
public:
    int passThePillow(int n, int time) {
        int ret = 1;
        for (int t = 0, diff = 1; t < time; ++t) {
            ret += diff;
            if (ret == n) {
                diff = -1;
            }
            else if (ret == 1) {
                diff = 1;
            }
        }

        return ret;
    }
};
