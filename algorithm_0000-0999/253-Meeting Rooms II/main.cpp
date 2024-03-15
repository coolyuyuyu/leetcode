class Solution {
public:
    int sweepline(const vector<vector<int>>& intervals) {
        map<int, int> diffs;
        for (const auto& interval : intervals) {
            int start = interval[0], end = interval[1];
            diffs[start] += 1;
            diffs[end] -= 1;
        }

        int ret = 0;
        int sum = 0;
        for (const auto& [_, diff] : diffs) {
            sum += diff;
            ret = std::max(ret, sum);
        }

        return ret;
    }

    int heap(vector<vector<int>>& intervals) {
        auto comp1 = [](const auto& interval1, const auto& interval2) {
            return interval1[0] < interval2[0];
        };
        std::sort(intervals.begin(), intervals.end(), comp1);
        auto comp2 = [](const auto& interval1, const auto& interval2) {
            return interval1[1] > interval2[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp2)> pq(comp2);

        int ret = 0;
        for (const auto& interval : intervals) {
            int start = interval[0], end = interval[1];
            while (!pq.empty() && pq.top()[1] <= start) {
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
