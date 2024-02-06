class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        int ret = 0;
        std::function<bool(int, int, int, int, int, int)> checkOk = [&](int e1, int e2, int l, int r, int b, int t) {
            for (int i = 0; i < n; ++i) {
                if (i == e1 || i == e2) { continue; }
                int x = points[i][0], y = points[i][1];
                if (l <= x && x <= r && b <= y && y <= t) {
                    return false;
                }
            }
            return true;
        };
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                vector<int> p1 = points[i], p2 = points[j];
                if (p1[0] > p2[0]) { std::swap(p1, p2); }
                if (p1[0] < p2[0] && p1[1] < p2[1]) { continue; }
                int l = std::min(p1[0], p2[0]), r = std::max(p1[0], p2[0]);
                int b = std::min(p1[1], p2[1]), t = std::max(p1[1], p2[1]);
                if (checkOk(i, j, l, r, b, t)) {
                    ++ret;
                }
            }
        }

        return ret;
    }
};
