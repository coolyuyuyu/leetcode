class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        std::sort(
            points.begin(), points.end(),
            [](const auto& p1, const auto& p2) {
                return (p1[0] < p2[0]) || (p1[0] == p2[0] && p1[1] > p2[1]);
            }
        );

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            int lo = INT_MIN, hi = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                if (lo < points[j][1] && points[j][1] <= hi) {
                    ++ret;

                    lo = points[j][1];
                }
            }
        }

        return ret;
    }
};
