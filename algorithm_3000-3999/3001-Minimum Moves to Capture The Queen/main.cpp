class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if (a == e && !(c == a && ((b < d && d < f) || (b > d && d > f)))) { return 1; }
        if (b == f && !(d == b && ((a < c && c < e) || (a > c && c > e)))) { return 1; }

        int dx1 = e - a, dy1 = f - b;
        int dx2 = e - c, dy2 = f - d;
        if (abs(dx2) == abs(dy2)) {
            if (abs(dx1) != abs(dy1)) { return 1; }
            if (dx1 * dx2 < 0 || dy1 * dy2 < 0) { return 1; }
            if (abs(dx1) > abs(dx2)) { return 1; }
        }

        return 2;
    }
};
