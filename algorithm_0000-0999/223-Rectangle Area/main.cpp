class Solution {
public:
    int computeArea(int x1, int y1, int x2, int y2) {
        return (x2 - x1) * (y2 - y1);
    }

    int computeInterset(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int lft = std::max(ax1, bx1), rht = std::min(ax2, bx2);
        int btm = std::max(ay1, by1), top = std::min(ay2, by2);
        if (rht <= lft || top <= btm) {
            return 0;
        }

        return (rht - lft) * (top - btm);
    }

    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        return computeArea(ax1, ay1, ax2, ay2) + computeArea(bx1, by1, bx2, by2) - computeInterset(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
    }
};
