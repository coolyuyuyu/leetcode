class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();

        int ret = k;
        for (int i = 0, wCnt = 0; i < n; ++i) {
            if (blocks[i] == 'W') {
                ++wCnt;
            }
            if (k <= i && blocks[i - k] == 'W') {
                --wCnt;
            }

            if (k <= i + 1) {
                ret = std::min(ret, wCnt);
            }
        }

        return ret;
    }
};
