class Solution {
public:
    int sumBase(int n, int k) {
        int ret = 0;
        for (; n; n /= k) {
            ret += n % k;
        }

        return ret;
    }
};
