class Solution {
public:
    int smallestRepunitDivByK(int k) {
        for (int ret = 1, rem = 0; ret <= k; ++ret) {
            rem = (rem * 10 + 1) % k;
            if (rem == 0) {
                return ret;
            }
        }

        return -1;
    }
};
