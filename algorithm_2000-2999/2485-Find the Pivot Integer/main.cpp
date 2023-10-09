class Solution {
public:
    int pivotInteger(int n) {
        for (int i = n / 2; i <= n; ++i) {
            if ((1 + i) * i == (i + n) * (n - i + 1)) {
                return i;
            }
        }

        return -1;
    }
};
