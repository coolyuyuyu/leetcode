class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        std::sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, std::greater<>> freePQ;
        for (int i = 0; i < n; ++i) {
            freePQ.push(i);
        }
        priority_queue<pair<long, int>, vector<pair<long, int>>, std::greater<>> busyPQ;

        vector<int> cnts(n, 0);
        for (const auto& meeting : meetings) {
            int bgn = meeting[0], end = meeting[1];
            while (!busyPQ.empty() && busyPQ.top().first <= bgn) {
                auto [_, i] = busyPQ.top();
                busyPQ.pop();
                freePQ.push(i);
            }

            if (!freePQ.empty()) {
                int i = freePQ.top();
                freePQ.pop();
                ++cnts[i];
                busyPQ.emplace(end, i);
            }
            else {
                auto [t, i] = busyPQ.top();
                busyPQ.pop();
                busyPQ.emplace(t + end - bgn, i);
                ++cnts[i];
            }
        }

        return std::distance(cnts.begin(), std::max_element(cnts.begin(), cnts.end()));
    }
};
