class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<vector<int>>& people = times;
        for (int i = 0; i < people.size(); ++i) {
            people[i].push_back(i);
        }
        std::sort(people.begin(), people.end(), [](const auto& p1, const auto& p2){ return p1[0] < p2[0]; });

        priority_queue<array<int, 2>, vector<array<int, 2>>, std::greater<array<int, 2>>> busyPQ; // <chairTime, chairIdx>
        priority_queue<array<int, 1>, vector<array<int, 1>>, std::greater<array<int, 1>>> freePQ; // <chairIdx>
        for (const auto& person : people) {
            int arrival = person[0], leaving = person[1], idx = person[2];
            while (!busyPQ.empty() && busyPQ.top()[0] <= arrival) {
                auto [chairTime, chairIdx] = busyPQ.top();
                busyPQ.pop();
                freePQ.push({chairIdx});
            }

            int chairIdx;
            if (freePQ.empty()) {
                chairIdx = busyPQ.size();
            }
            else {
                chairIdx = freePQ.top()[0];
                freePQ.pop();
            }
            busyPQ.push({leaving, chairIdx});

            if (idx == targetFriend) {
                return chairIdx;
            }
        }

        assert(false);
        return -1;
    }
};
