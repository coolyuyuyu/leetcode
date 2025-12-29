class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        std::sort(events.begin(), events.end(), [](const auto& e1, const auto& e2){ return e1[1] < e2[1]; });

        // maxs[i]: the max val of values from events[0:i]
        // ends[i]: the endTime of events[i]
        vector<int> maxs(n), ends(n);

        int ret = 0;
        for (int i = 0; i < events.size(); ++i) {
            int bgn = events[i][0], end = events[i][1], val = events[i][2];
            ret = std::max(ret, val);

            auto itr = std::lower_bound(ends.begin(), ends.begin() + i, bgn);
            if (itr != ends.begin()) {
                itr = std::prev(itr);
                int idx = std::distance(ends.begin(), itr);
                ret = std::max(ret, maxs[idx] + val);
            }

            ends[i] = end;
            maxs[i] = std::max(i > 0 ? maxs[i - 1] : 0, val);
        }

        return ret;
    }
};
