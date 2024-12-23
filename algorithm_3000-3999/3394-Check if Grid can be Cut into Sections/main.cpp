class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        std::function<bool(const vector<pair<int, int>>&)> checkOk = [](const vector<pair<int, int>>& intervals) {
            int cnt = 0, rhtMost = INT_MIN;
            for (const auto& [bgn, end] : intervals) {
                if (rhtMost <= bgn) {
                    if (++cnt >= 3) {
                        return true;
                    }
                    rhtMost = end;
                }
                else {
                    rhtMost = std::max(rhtMost, end);
                }
            }
            return false;
        };

        vector<pair<int, int>> intervals;
        std:function<bool(const pair<int, int>& p1, const pair<int, int>& p2)> cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first < p2.first;
        };

        intervals.clear();
        for (const auto& rect : rectangles) {
            int lft = rect[0], btm = rect[1], rht = rect[2], top = rect[3];
            intervals.emplace_back(lft, rht);
        }
        std::sort(intervals.begin(), intervals.end(), cmp);
        if (checkOk(intervals)) {
            return true;
        }
        
        intervals.clear();
        for (const auto& rect : rectangles) {
            int lft = rect[0], btm = rect[1], rht = rect[2], top = rect[3];
            intervals.emplace_back(btm, top);
        }
        std::sort(intervals.begin(), intervals.end(), cmp);
        return checkOk(intervals);
    }
};
