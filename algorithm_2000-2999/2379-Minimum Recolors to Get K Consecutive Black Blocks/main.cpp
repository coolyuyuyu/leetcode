class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ret = k;
        for (int i = 0, w = 0, n = blocks.size(); i < n; ++i) {
            if (blocks[i] == 'W') { ++w; }
            if (i - k + 1 >= 0) {
                ret = std::min(ret, w);
                if (blocks[i - k + 1] == 'W') { --w; }
            }
        }

        return ret;
    }
};
