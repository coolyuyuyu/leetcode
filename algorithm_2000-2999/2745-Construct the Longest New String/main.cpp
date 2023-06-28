class Solution {
public:
    int longestString(int x, int y, int z) {
        int ret = 0;

        if (x == y) {
            ret += (4 * x);
        }
        else {
            ret += 2 * (std::min(x, y) * 2  + 1);
        }
        ret += (2 * z);

        return ret;
    }
};
