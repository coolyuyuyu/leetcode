class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> x2yset;
        for (const auto& pnt : points) {
            int x = pnt[0], y = pnt[1];
            x2yset[x].insert(y);
        }

        int ret = INT_MAX;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                if (x1 == x2 || y1 == y2) { continue; }

                int x3 = x1, y3 = y2;
                int x4 = x2, y4 = y1;
                if (x2yset[x3].find(y3) == x2yset[x3].end()) { continue; }
                if (x2yset[x4].find(y4) == x2yset[x4].end()) { continue; }

                ret = std::min(ret, std::abs(x2 - x1) * std::abs(y2 - y1));
            }
        }

        return ret != INT_MAX ? ret : 0;
    }
};
