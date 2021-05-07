class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int secs = 0;
        for (size_t i = 1; i < points.size(); ++i) {
            secs += max(abs(points[i][0] - points[i - 1][0]), abs(points[i][1] - points[i - 1][1]));
        }

        return secs;
    }
};
