class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ret = 0;

        // distrinute candies to a, b and c
        int aMin = std::max(0, n - 2 * limit);
        int aMax = std::min(limit, n);
        for (int a = aMin; a <= aMax; ++a) {
            int bMin = std::max(0, n - a - limit);
            int bMax = std::min(limit, n - a);

            ret += bMax - bMin + 1;
        }

        return ret;
    }
};
