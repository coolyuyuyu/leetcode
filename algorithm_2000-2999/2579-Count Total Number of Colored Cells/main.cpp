class Solution {
public:
    long long coloredCells(int n) {
        // 1 + (4 + 8 + 12 + ... 4(n-1))
        // 1 + (a0 + a1 + ... + an-2)

        return 1 + ((4LL) + (4LL * (n - 1))) * (n - 1) / 2;
    }
};
