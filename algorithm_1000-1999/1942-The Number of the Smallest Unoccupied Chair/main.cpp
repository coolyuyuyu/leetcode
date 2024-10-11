class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<tuple<int, int, int>> people(n); // <arrival, leaving, i>
        for (int i = 0; i < n; ++i) {
            int arrival = times[i][0], leaving = times[i][1];
            people[i] = {arrival, leaving, i};
        }
        std::sort(people.begin(), people.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> busyPQ; // <leaving, chairIdx>
        priority_queue<int, vector<int>, std::greater<int>> freePQ; // chairIdx
        for (const auto& [arrival, leaving, i] : people) {
            while (!busyPQ.empty() && busyPQ.top().first <= arrival) {
                const auto [_, chairIdx] = busyPQ.top();
                busyPQ.pop();
                freePQ.push(chairIdx);
            }

            int chairIdx;
            if (freePQ.empty()) {
                chairIdx = busyPQ.size();
            }
            else {
                chairIdx = freePQ.top();
                freePQ.pop();
            }
            busyPQ.emplace(leaving, chairIdx);

            if (i == targetFriend) {
                return chairIdx;
            }
        }
        __builtin_unreachable();

        return -1;
    }
};
