class Solution {
public:
    int distributeCandies(int n, int limit) {
        long long ret = 0;

        // distrinute candies to a, b and c
        for (int a = 0; a <= limit; ++a) {
            for (int b = 0; b <= limit; ++b) {
                for (int c = 0; c <= limit; ++c) {
                    if (a + b + c == n) {
                        ++ret;
                    }
                }
            }
        }

        return ret;
    }
};
