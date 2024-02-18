class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [](const auto& m1, const auto& m2){ return m1[0] < m2[0]; });

        priority_queue<pair<long, int>, vector<pair<long, int>>, std::greater<pair<long, int>>> busyPQ; // <endTtime, idx>
        priority_queue<int, vector<int>, std::greater<int>> freePQ; // idx
        for (int i = 0; i < n; ++i) {
            freePQ.push(i);
        }

        int cnts[n];
        std::fill(cnts, cnts + n, 0);
        for (int i = 0; i < meetings.size(); ++i) {
            int start = meetings[i][0], end = meetings[i][1];
            while (!busyPQ.empty() && busyPQ.top().first <= start) {
                freePQ.push(busyPQ.top().second);
                busyPQ.pop();
            }

            if (freePQ.empty()) {
                auto [time, idx] = busyPQ.top();
                busyPQ.pop();

                ++cnts[idx];
                busyPQ.emplace(time + end - start, idx);
            }
            else {
                int idx = freePQ.top();
                freePQ.pop();
                ++cnts[idx];
                busyPQ.emplace(end, idx);
            }
        }

        return std::max_element(cnts, cnts + n) - cnts;
    }
};
