class Solution {
public:
    int mirrorDistance(int n) {
        int m = 0;
        for (int num = n; num; num /= 10) {
            m = m * 10 + num % 10;
        }

        return std::abs(n - m);
    }
};
