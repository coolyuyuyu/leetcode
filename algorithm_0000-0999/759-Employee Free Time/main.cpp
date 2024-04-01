/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> byDiffArray(vector<vector<Interval>> schedule) {
        map<int, int> diffs;
        for (const auto& intervals : schedule) {
            for (const auto& interval : intervals) {
                int bgn = interval.start, end = interval.end;
                diffs[bgn] += 1;
                diffs[end] -= 1;
            }
        }

        vector<Interval> ret;

        int sum = 0, pre = INT_MIN;
        for (const auto [cur, diff] : diffs) {
            if (sum == 0) {
                if (pre != INT_MIN) {
                    ret.emplace_back(pre, cur);
                }
            }
            sum += diff;
            pre = cur;
        }

        return ret;
    }

    vector<Interval> bySweepLine(vector<vector<Interval>> schedule) {
        vector<pair<int, int>> diffs;
        for (const auto& intervals : schedule) {
            for (const auto& interval : intervals) {
                int bgn = interval.start, end = interval.end;
                diffs.emplace_back(bgn, +1);
                diffs.emplace_back(end, -1);
            }
        }
        std::sort(diffs.begin(), diffs.end(), [](const auto& diff1, const auto& diff2){ return (diff1.first < diff2.first || (diff1.first == diff2.first && diff1.second > diff2.second)); });

        vector<Interval> ret;

        int sum = 0, bgn = INT_MIN, end = INT_MIN;
        for (const auto [cur, diff] : diffs) {
            sum += diff;
            if (sum == 0 && diff == -1) {
                bgn = cur;
            }
            else if (sum == 1 && diff == 1 && bgn != INT_MIN) {
                end = cur;
                ret.emplace_back(bgn, end);
            }
        }

        return ret;
    }

    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        //return byDiffArray(schedule);
        return bySweepLine(schedule);
    }
};
