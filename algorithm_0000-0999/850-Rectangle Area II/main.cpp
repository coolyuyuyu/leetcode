class Solution {
public:
    int M = 1e9 + 7;

    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<tuple<int, bool, int, int>> events;
        for (const auto& rect : rectangles) {
            int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
            events.emplace_back(y1, true, x1, x2);
            events.emplace_back(y2, false, x1, x2);
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

        int ret = 0;

        multiset<pair<int, int>> intervals;
        for (int i = 0; i < events.size(); ++i) {
            const auto& [y, t, x1, x2] =  events[i];
            if (i > 0 && y > std::get<0>(events[i - 1])) {
                int preY = std::get<0>(events[i - 1]);
                int h = y - preY;
                int w = computeUnionWidth(intervals);
                ret += (1LL * h * w) % M;
                ret %= M;
            }
            if (t) {
                intervals.insert({x1, x2});
            }
            else {
                intervals.erase(intervals.find({x1, x2}));
            }
        }

        return ret;
    }
};
