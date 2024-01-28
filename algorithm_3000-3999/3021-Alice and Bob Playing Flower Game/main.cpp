class Solution {
public:
    long long flowerGame(int n, int m) {
        long long cntE1 = n / 2;
        long long cntO1 = n - cntE1;
        long long cntE2 = m / 2;
        long long cntO2 = m - cntE2;
        return cntE1 * cntO2 + cntO1 * cntE2;
    }
};
