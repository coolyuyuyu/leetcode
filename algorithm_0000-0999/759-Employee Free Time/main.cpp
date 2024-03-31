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
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
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
            if (sum == 0 && diff > 0) {
                if (pre != INT_MIN) {
                    ret.emplace_back(pre, cur);
                }
            }
            sum += diff;
            pre = cur;
        }

        return ret;
    }
};
