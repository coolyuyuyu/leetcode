class Solution {
public:
    int M = 1e9 + 7;

    int maximumXorProduct(long long a, long long b, int n) {
        for (int i = 0; i < n; ++i) {
            int b1 = (a >> i) & 1;
            int b2 = (b >> i) & 1;
            if (b1 == b2) {
                if (b1 == 0) {
                    a |= (1LL) << i;
                    b |= (1LL) << i;
                }
                continue;
            }

            a &= ~(1LL << i);
            b &= ~(1LL << i);
            if (a <= b) {
                a |= (1LL << i);
            }
            else {
                b |= (1LL << i);
            }
        }

        return (a % M) * (b % M) % M;
    }
};
