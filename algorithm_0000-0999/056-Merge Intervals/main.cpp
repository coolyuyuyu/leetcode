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
    class End {
    public:
        enum Type{UP, DOWN};
        End(int p, Type t)
            : pos(p)
            , type(t){
        }

        bool operator < (const End& end) {
            return (pos != end.pos ? pos < end.pos : type < end.type);
        }

        int pos;
        Type type;
    };

    vector<Interval> merge(vector<Interval>& intervals) {
        vector<End> ends;
        ends.reserve(intervals.size() * 2);
        for (size_t i = 0; i < intervals.size(); ++i) {
            ends.push_back(End(intervals[i].start, End::UP));
            ends.push_back(End(intervals[i].end, End::DOWN));
        }
        sort(ends.begin(), ends.end());

        vector<Interval> ret;
        int count = 0;
        int start = 0;
        for (size_t i = 0; i < ends.size(); ++i) {
            if (ends[i].type == End::UP) {
                if (count == 0) {
                    start = ends[i].pos;
                }
                count += 1;
            }
            else {
                if (count == 1) {
                    ret.push_back(Interval(start, ends[i].pos));
                }
                count -= 1;
            }
        }

        return ret;
    }
};