class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        std::function<bool(vector<pair<int, int>>&)> f = [](vector<pair<int, int>>& intervals) {
            std::sort(intervals.begin(), intervals.end());

            int cnt = 0, most = INT_MIN;
            for (const auto& [bgn, end] : intervals) {
                if (bgn >= most) {
                    if (++cnt > 2) {
                        return true;
                    }
                    most = end;
                }
                else {
                    most = std::max(most, end);
                }
            }

            return false;
        };

        vector<pair<int, int>> intervals;

        intervals.clear();
        for (const auto& rect : rectangles) {
            int lft = rect[0], rht = rect[2];
            intervals.emplace_back(lft, rht);
        }
        if (f(intervals)) {
            return true;
        }

        intervals.clear();
        for (const auto& rect : rectangles) {
            int btm = rect[1], top = rect[3];
            intervals.emplace_back(btm, top);
        }
        if (f(intervals)) {
            return true;
        }

        return false;
    }
};
