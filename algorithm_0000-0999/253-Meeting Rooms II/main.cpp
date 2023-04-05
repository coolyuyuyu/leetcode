class Solution {
public:
    int sweepline(const vector<vector<int>>& intervals) {
        map<int, int> m; // time -> diff
        for (const auto& interval : intervals) {
            ++m[interval[0]];
            --m[interval[1]];
        }

        int ret = 0;
        int sum = 0;
        for (const auto& [_, diff] : m) {
            sum += diff;
            ret = std::max(ret, sum);
        }

        return ret;
    }

    int heap(vector<vector<int>>& intervals) {
        auto cmp1 = [](const vector<int>& i1, const vector<int>& i2) { return i1[0] < i2[0]; };
        sort(intervals.begin(), intervals.end(), cmp1);

        int ret = 0;
        auto cmp2 = [](const vector<int>& i1, const vector<int>& i2) { return i1[1] > i2[1]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp2)> pq(cmp2);
        for (const auto& interval : intervals) {
            while (!pq.empty() && pq.top()[1] <= interval[0]) {
                pq.pop();
            }
            pq.push(interval);

            ret = std::max<int>(ret, pq.size());
        }

        return ret;
    }

    int minMeetingRooms(vector<vector<int>>& intervals) {
        //return sweepline(intervals);
        return heap(intervals);
    }
};
