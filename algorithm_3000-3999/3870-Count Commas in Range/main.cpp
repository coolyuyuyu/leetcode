class Solution {
public:
    int countCommas(int n) {
        int ret = 0;
        for (int base = 1000; base <= n; base *= 1000) {
            ret += n - base + 1;
        }

        return ret;
    }
};
