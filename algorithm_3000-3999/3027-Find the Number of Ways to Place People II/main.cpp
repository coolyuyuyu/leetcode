class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        auto comp = [](const vector<int>& p1, const vector<int>& p2) {
            int x1 = p1[0], y1 = p1[1];
            int x2 = p2[0], y2 = p2[1];
            return x1 < x2 || (x1 == x2 && y1 > y2);
        };
        std::sort(points.begin(), points.end(), comp);

        int n = points.size();
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            int yLo = INT_MIN, yHi = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                if (yHi >= points[j][1] && points[j][1] > yLo) {
                    yLo = points[j][1];
                    ++ret;
                }
            }
        }

        return ret;
    }
};
