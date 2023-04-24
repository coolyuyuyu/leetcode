class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ret = -1;
        for (int i = 0, minDist = INT_MAX; i < points.size(); ++i) {
            if (points[i][0] == x || points[i][1] == y) {
                int dist = abs(points[i][0] - x) + abs(points[i][1] - y);
                if (dist < minDist) {
                    minDist = dist;
                    ret = i;
                }
            }
        }

        return ret;
    }
};
