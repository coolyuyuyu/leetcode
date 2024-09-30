class Solution {
public:
    char findKthBit(int n, int k) {
        --k;

        int len = 1;
        for (int i = 1; i < n; ++i) {
            len = len * 2 + 1;
        }

        int flip = 0;
        while (len > 1) {
            int sublen = (len - 1) / 2;
            if (k == sublen) {
                return flip & 1 ? '0' : '1';
            }

            if (k > sublen) {
                k = sublen * 2 - k;
                ++flip;
            }
            len = sublen;
        }

        return flip & 1 ? '1' : '0';
    }
};
