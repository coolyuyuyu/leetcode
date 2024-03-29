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
        auto bgn = std::lower_bound(
            intervals.begin(), intervals.end(),
            vector<int>{0, newInterval[0]},
            [](const vector<int>& i1, const vector<int>& i2) { return i1[1] < i2[1]; });
        auto end = std::upper_bound(
            intervals.begin(), intervals.end(),
            vector<int>{newInterval[1], 0},
            [](const vector<int>& i1, const vector<int>& i2) { return i1[0] < i2[0]; });

        return {bgn, end};
    }

    vector<vector<int>> byBinarySearch(vector<vector<int>>& intervals, vector<int>& newInterval) {
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

    vector<vector<int>> byLinearSearch(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;

        int i = 0, n = intervals.size();
        for (; i < n && intervals[i][1] < newInterval[0]; ++i) {
            ret.push_back(intervals[i]);
        }

        for (; i < n && intervals[i][0] <= newInterval[1]; ++i) {
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
        }
        ret.push_back(newInterval);

        for (; i < n; ++i) {
            ret.push_back(intervals[i]);
        }

        return ret;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //return byBinarySearch(intervals, newInterval);
        return byLinearSearch(intervals, newInterval);
    }
};
