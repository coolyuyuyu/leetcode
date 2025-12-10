class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        // y = ax + b
        // => dx = (x1 - x2), dy = (y1 - y2)
        // => a = dy / dx
        // => b = (y1 * dx - x1 * dy) / dx

        unordered_map<float, vector<float>> slope2intercepts;
        unordered_map<int, vector<float>> mid2slopes;
        for (int i = 0, n = points.size(); i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                int dx = (x1 - x2), dy = (y1 - y2);

                float a, b;
                if (dx == 0) {
                    a = std::numeric_limits<float>::infinity();;
                    b = x1;
                }
                else {
                    a = 1.0f * dy / dx;
                    b = 1.0f * (y1 * dx - x1 * dy) / dx;
                }

                slope2intercepts[a].push_back(b);
                mid2slopes[(x1 + x2) * 10000 + (y1 + y2)].push_back(a);
            }
        }

        int ret = 0;
        for (const auto& [_, intercepts] : slope2intercepts) {
            if (intercepts.size() == 1) {
                continue;
            }

            unordered_map<float, int> intercept2cnt;
            for (float intercept : intercepts) {
                ++intercept2cnt[intercept];
            }

            int sum = 0;
            for (const auto& [_, cnt] : intercept2cnt) {
                ret += cnt * sum;
                sum += cnt;
            }
        }
        for (const auto& [_, slopes] : mid2slopes) {
            if (slopes.size() == 1) {
                continue;
            }

            unordered_map<float, int> slope2cnt;
            for (float slope : slopes) {
                ++slope2cnt[slope];
            }

            int sum = 0;
            for (const auto& [_, cnt] : slope2cnt) {
                ret -= cnt * sum;
                sum += cnt;
            }
        }

        return ret;
    }
};
