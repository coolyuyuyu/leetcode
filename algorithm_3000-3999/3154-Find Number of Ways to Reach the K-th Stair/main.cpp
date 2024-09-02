class Solution {
public:
    int waysToReachStair(int k) {
        // Alice can go up to (1 << jump) purely by op2
        // Alice can use op1 ((1 << jump) - k) times to go down from (1 << jump) stairs to k
        // There are at most (jump + 1) chances to use op1

        std::function<int(int, int)> comb = [](int n, int k) {
            if (k < 0 || k > n) { return 0; }
            long ret = 1;
            for (int i = 0; i < k; ++i) {
                ret = ret * (n - i) / (i + 1);
            }

            return static_cast<int>(ret);
        };

        int ret = 0;
        for (int jump = 0; jump < 31; ++jump) {
            ret += comb(jump + 1, (1 << jump) - k);
        }

        return ret;
    }
};
