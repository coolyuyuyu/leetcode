class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            int same = 0;
            int vertical = 0;
            map<pair<int, int>, int> counts;
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }
                if (points[i] == points[j]) {
                    ++same;
                    continue;
                }
                if (points[j][0] == points[i][0]) {
                    ++vertical;
                    continue;
                }

                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];
                int gcd = std::gcd(dy, dx);
                ++counts[{dy / gcd, dx / gcd}];
            }

            //ret = std::max(ret, same + 1);
            ret = std::max(ret, same + vertical + 1);
            for (const auto& [slope, cnt] : counts) {
                ret = std::max(ret, cnt + same + 1);
            }
        }

        return ret;
    }
};
