class Solution {
public:
    long long coloredCells(int n) {
        long long a = 4;
        long long b = (long long)(n - 1) * 4;
        long long c = (a + b) * (n - 1) / 2;
        return c + 1;
    }
};
