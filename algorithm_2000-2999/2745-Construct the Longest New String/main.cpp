class Solution {
public:
    int longestString(int x, int y, int z) {
        int cnt = 2 * std::min(x, y) + (x == y ? 0 : 1) + z;
        return cnt * 2;
    }
};
