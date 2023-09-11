class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dx = abs(sx - fx), dy = abs(sy - fy);
        if (dx == 0 && dy == 0 && t == 1) {
            return false;
        }

        return std::max(dx, dy) <= t;
    }
};
