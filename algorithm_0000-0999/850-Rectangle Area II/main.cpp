class Solution {
public:
    int M = 1e9 + 7;

    int f1(vector<vector<int>>& rectangles) {
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

    int f2(vector<vector<int>>& rectangles) {
        vector<int> xvals, yvals;
        unordered_map<int, int> x2idx, y2idx;
        {
            set<int> xset, yset;
            for (const auto& rect : rectangles) {
                int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
                xset.insert(x1);
                yset.insert(y1);
                xset.insert(x2);
                yset.insert(y2);
            }

            xvals.assign(xset.begin(), xset.end());
            yvals.assign(yset.begin(), yset.end());

            for (int i = 0; i < xvals.size(); ++i) {
                x2idx[xvals[i]] = i;
            }
            for (int j = 0; j < yvals.size(); ++j) {
                y2idx[yvals[j]] = j;
            }
        }
        int m = xvals.size(), n = yvals.size();

        int diffs[m][n];
        std::fill(&diffs[0][0], &diffs[0][0] + m * n, 0);
        for (const auto& rect : rectangles) {
            int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
            int xidx1 = x2idx[x1], yidx1 = y2idx[y1], xidx2 = x2idx[x2] - 1, yidx2 = y2idx[y2] - 1;
            diffs[xidx1][yidx1] += 1;
            if (xidx2 + 1 < m) { diffs[xidx2 + 1][yidx1] -= 1; }
            if (yidx2 + 1 < n) { diffs[xidx1][yidx2 + 1] -= 1; }
            if (xidx2 + 1 < m && yidx2 + 1 < n) { diffs[xidx2 + 1][yidx2 + 1] += 1; }
        }

        int sums[m][n];
        std::fill(&sums[0][0], &sums[0][0] + m * n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0) { sums[i][j] += sums[i - 1][j]; }
                if (j > 0) { sums[i][j] += sums[i][j - 1]; }
                if (i > 0 && j > 0) { sums[i][j] -= sums[i - 1][j - 1]; }
                sums[i][j] += diffs[i][j];
            }
        }

        int ret = 0;
        for (int i = 0; i + 1 < m; ++i) {
            for (int j = 0; j + 1 < n; ++j) {
                if (sums[i][j]>0) {
                    int dx = xvals[i + 1] - xvals[i];
                    int dy = yvals[j + 1] - yvals[j];
                    ret += 1LL * dx * dy % M;
                    ret %= M;
                }
            }
        }

        return ret;
    }

    int rectangleArea(vector<vector<int>>& rectangles) {
        //return f1(rectangles);
        return f2(rectangles);
    }
};
