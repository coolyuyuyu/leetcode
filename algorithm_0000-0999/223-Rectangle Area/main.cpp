class Solution {
public:
    int computeIntersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
        int lft = max(x1, x3), rht = min(x2, x4);
        int btm = max(y1, y3), top = min(y2, y4);
        if (rht <= lft || top <= btm) {
            return 0;
        }

        return (rht - lft) * (top - btm);
    }

    int computeArea(int x1, int y1, int x2, int y2) {
        return (x2 - x1) * (y2 - y1);
    }

    int computeArea(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
        return computeArea(x1, y1, x2, y2) - computeIntersect(x1, y1, x2, y2, x3, y3, x4, y4) + computeArea(x3, y3, x4, y4);
    }
};