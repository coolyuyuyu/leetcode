class Solution {
public:
    int sweepline(const vector<vector<int>>& intervals) {
        map<int, int> m; // time -> diff
        for (const auto& interval : intervals) {
            int lft = interval[0], rht = interval[1];
            ++m[lft];
            --m[rht + 1];
        }

        int ret = 0, sum = 0;
        for (const auto& [_, diff] : m) {
            sum += diff;
            ret = std::max(ret, sum);
        }

        return ret;
    }

    int heap(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());

        int ret = 0;
        priority_queue<int, vector<int>, std::greater<>> pq;
        for (const auto& interval : intervals) {
            while (!pq.empty() && pq.top() < interval[0]) {
                pq.pop();
            }
            pq.push(interval[1]);

            ret = std::max<int>(ret, pq.size());
        }

        return ret;
    }

    int minGroups(vector<vector<int>>& intervals) {
        return sweepline(intervals);
        //return heap(intervals);
    }
};
