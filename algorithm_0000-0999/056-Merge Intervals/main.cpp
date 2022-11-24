class Solution {
public:
    // Time: O(n), Space: O(n)
    vector<vector<int>> merge1(vector<vector<int>>& intervals) {
        class End {
        public:
            enum Type {UP, DOWN};
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

        vector<End> ends;
        ends.reserve(intervals.size() * 2);
        for (size_t i = 0; i < intervals.size(); ++i) {
            ends.push_back(End(intervals[i][0], End::UP));
            ends.push_back(End(intervals[i][1], End::DOWN));
        }
        sort(ends.begin(), ends.end());

        vector<vector<int>> ret;
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
                    ret.push_back({start, ends[i].pos});
                }
                count -= 1;
            }
        }

        return ret;
    }

    // Time: O(n), Space: O(1)
    vector<vector<int>> merge2(vector<vector<int>>& intervals) {
        auto comp = [](vector<int>& interval1, vector<int>& interval2) -> bool {
            return interval1[0] < interval2[0] || (interval1[0] == interval2[0] && interval2[1] < interval2[1]);
        };
        std::sort(intervals.begin(), intervals.end(), comp);

        size_t i = 0;
        for (size_t j = 1; j < intervals.size(); ++j) {
            if (intervals[j][0] <= intervals[i][1]) {
                intervals[i][1] = std::max(intervals[i][1], intervals[j][1]);

            }
            else if (i < j){
                intervals[++i] = intervals[j];
            }
        }
        intervals.erase(intervals.begin() + i + 1, intervals.end());

        return intervals;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //return merge1(intervals);
        return merge2(intervals);
    }
};
