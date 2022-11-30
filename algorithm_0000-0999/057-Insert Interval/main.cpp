class Solution {
public:
    // binary search
    std::pair<vector<vector<int>>::iterator, vector<vector<int>>::iterator> searchInsert1(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto bgn = intervals.begin();
        for (auto rht = intervals.end(); bgn < rht;) {
            auto mid = bgn + std::distance(bgn, rht) / 2;
            if (newInterval[0] <= mid->at(1)) {
                rht = mid;
            }
            else {
                bgn = mid + 1;
            }
        }

        auto end = intervals.end();
        for (auto lft = bgn; lft < end;) {
            auto mid = lft + std::distance(lft, end) / 2;
            if (newInterval[1] < mid->at(0)) {
                end = mid;
            }
            else {
                lft = mid + 1;
            }
        }

        return {bgn, end};
    }

    // pure std
    std::pair<vector<vector<int>>::iterator, vector<vector<int>>::iterator> searchInsert2(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto bgn = std::lower_bound(
            intervals.begin(), intervals.end(),
            vector<int>{-1, newInterval[0]},
            [](const vector<int>& i1, const vector<int>& i2) {
                return i1[1] < i2[1];
            });
        auto end = std::upper_bound(
            bgn, intervals.end(),
            vector<int>{newInterval[1], -1},
            [](const vector<int>& i1, const vector<int>& i2) {
                return i1[0] < i2[0];
            });
        return {bgn, end};
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //auto p = searchInsert1(intervals, newInterval);
        auto p = searchInsert2(intervals, newInterval);
        auto bgn = p.first, end = p.second;
        if (bgn == end) {
            intervals.insert(bgn, newInterval);
        }
        else {
            bgn->at(0) = std::min(bgn->at(0), newInterval[0]);
            bgn->at(1) = std::max((end - 1)->at(1), newInterval[1]);
            intervals.erase(bgn + 1, end);
        }

        return intervals;
    }
};
