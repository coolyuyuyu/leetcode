class Solution {
public:
    int minAllOneMultiple(int k) {
        int n = 1, r = n % k;
        for (; r != 0 && n <= k; ++n) {
            r = (r * 10 + 1) % k;
        }

        return r == 0 ? n : -1;
    }
};
