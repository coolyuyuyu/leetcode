class Solution {
public:
    // handmade binary search
    pair<vector<vector<int>>::iterator, vector<vector<int>>::iterator> searchInsert1(vector<vector<int>>& intervals, const vector<int>& newInterval) {
        auto bgn = intervals.begin();
        for (auto rht = intervals.end(); bgn < rht;) {
            auto mid = std::next(bgn, std::distance(bgn, rht) / 2);
            if (newInterval[0] <= mid->at(1)) {
                rht = mid;
            }
            else {
                bgn = std::next(mid);
            }
        }

        auto end = intervals.end();
        for (auto lft = bgn; lft < end;) {
            auto mid = std::next(lft, std::distance(lft, end) / 2);
            if (newInterval[1] < mid->at(0)) {
                end = mid;
            }
            else {
                lft = std::next(mid);
            }
        }

        return {bgn, end};
    }

    // pure std
    pair<vector<vector<int>>::iterator, vector<vector<int>>::iterator> searchInsert2(vector<vector<int>>& intervals, const vector<int>& newInterval) {
        auto bgn = std::lower_bound(intervals.begin(), intervals.end(), vector<int>{0, newInterval[0]},
            [](const vector<int>& interval1, const vector<int>& interval2) {
                return interval1[1] < interval2[1];
            });
        auto end = std::upper_bound(bgn, intervals.end(), vector<int>{newInterval[1], 0},
            [](const vector<int>& interval1, const vector<int>& interval2) {
                return interval1[0] < interval2[0];
            });

        return {bgn, end};
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //auto [bgn, end] = searchInsert1(intervals, newInterval);
        auto [bgn, end] = searchInsert2(intervals, newInterval);
        if (bgn == end) {
            intervals.insert(bgn, newInterval);
        }
        else {
            bgn->at(0) = std::min(bgn->at(0), newInterval[0]);
            bgn->at(1) = std::max(std::prev(end)->at(1), newInterval[1]);
            intervals.erase(bgn + 1, end);
        }

        return intervals;
    }
};
