class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<tuple<int, bool, int, int>> events;
        for (const auto& square : squares) {
            int x = square[0], y = square[1], l = square[2];
            events.emplace_back(y, true, x, x + l);
            events.emplace_back(y + l, false, x, x + l);
        }
        std::sort(events.begin(), events.end());

        std::function<int(const multiset<pair<int, int>>&)> computeUnionWidth = [](const multiset<pair<int, int>>& intervals) {
            int ret = 0;
            int end = INT_MIN;
            for (const auto& [a, b] : intervals) {
                if (a > end) {
                    ret += (b - a);
                    end = b;
                }
                else if (b > end) {
                    ret += (b - end);
                    end = b;
                }
            }

            return ret;
        };

        multiset<pair<int, int>> intervals;
        long long total = 0;
        vector<tuple<int, int, int>> areas;
        for (int i = 0; i < events.size(); ++i) {
            const auto& [y, t, x1, x2] =  events[i];
            if (i > 0 && y > std::get<0>(events[i - 1])) {
                int preY = std::get<0>(events[i - 1]);
                int h = y - preY;
                int w = computeUnionWidth(intervals);
                areas.emplace_back(preY, h, w);
                total += 1LL * h * w;
            }
            if (t) {
                intervals.insert({x1, x2});
            }
            else {
                intervals.erase(intervals.find({x1, x2}));
            }
        }

        double half = 1.0 * total / 2;
        long long acc = 0;
        for (const auto& [y, h, w] : areas) {
            if (acc + 1LL * h * w >= half) {
                return y + (half - acc) / w;
            }
            acc += 1LL * h * w;
        }
        __builtin_unreachable();

        return 0.0;
    }
};
