/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    pair<size_t, size_t> searchInsert(vector<Interval>& intervals, const Interval& newInterval) {
        size_t lft, rht;
        size_t bgn, end;

        lft = 0, rht = intervals.size();
        while (lft < rht) {
            size_t mid = lft + (rht - lft) / 2;
            if (newInterval.start <= intervals[mid].end) {
                rht = mid;
            }
            else {
                lft = mid + 1;
            }
        }
        bgn = rht;

        lft = 0, rht = intervals.size();
        while (lft < rht) {
            size_t mid = lft + (rht - lft) / 2;
            if (newInterval.end + 1 <= intervals[mid].start) {
                rht = mid;
            }
            else {
                lft = mid + 1;
            }
        }
        end = rht;

        return {bgn, end};
    }

    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        pair<size_t, size_t> p = searchInsert(intervals, newInterval);
        size_t bgn = p.first, end = p.second;

        vector<Interval> result;
        result.insert(result.end(), intervals.begin(), intervals.begin() + bgn);

        if (bgn == end) {
            result.emplace_back(newInterval);
        }
        else {
            result.emplace_back(Interval(min(intervals[bgn].start, newInterval.start), max(intervals[end - 1].end, newInterval.end)));
        }

        result.insert(result.end(), intervals.begin() + end, intervals.end());

        return result;
    }
};