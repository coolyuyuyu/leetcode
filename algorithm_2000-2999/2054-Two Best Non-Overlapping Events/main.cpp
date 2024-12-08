class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        std::sort(events.begin(), events.end(), [](const auto& e1, const auto& e2){ return e1[1] < e2[1]; });

        // maxs[i]: the max val of values from events[0:i]
        int maxs[n];
        for (int i = 0, mx = 0; i < n; ++i) {
            mx = std::max(mx, events[i][2]);
            maxs[i] = mx;
        }

        int ret = 0;

        vector<int> ends;
        for (int i = 0; i < events.size(); ++i) {
            int bgn = events[i][0], end = events[i][1], val = events[i][2];
            ret = std::max(ret, val);

            auto itr = std::upper_bound(ends.begin(), ends.end(), bgn - 1);
            if (itr != ends.begin()) {
                itr = std::prev(itr);
                int idx = std::distance(ends.begin(), itr);
                ret = std::max(ret, maxs[idx] + val);
            }
            ends.push_back(end);
        }

        return ret;
    }
};
