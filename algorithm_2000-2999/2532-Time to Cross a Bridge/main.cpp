class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        priority_queue<pair<int, int>> lftWait, rhtWait;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> lftWork, rhtWork;

        for (int id = 0; id < k; ++id) {
            lftWait.emplace(time[id][0] + time[id][2], id);
        }

        int curTime = 0;
        for (int crossed = 0, returned = 0; returned < n;) {
            if (crossed == n) {
                while (!lftWait.empty()) {
                    lftWait.pop();
                }
            }

            while (!lftWork.empty() && lftWork.top().first <= curTime) {
                auto [_, id] = lftWork.top();
                lftWork.pop();
                lftWait.emplace(time[id][0] + time[id][2], id);
            }
            while (!rhtWork.empty() && rhtWork.top().first <= curTime) {
                auto [_, id] = rhtWork.top();
                rhtWork.pop();
                rhtWait.emplace(time[id][0] + time[id][2], id);
            }

            if (lftWait.empty() && rhtWait.empty()) {
                int lftTime = lftWork.empty() ? INT_MAX : lftWork.top().first;
                int rhtTime = rhtWork.empty() ? INT_MAX : rhtWork.top().first;
                curTime = std::min(lftTime, rhtTime);
            }

            if (!rhtWait.empty()) {
                auto [_, id] = rhtWait.top();
                rhtWait.pop();

                curTime += time[id][2];
                lftWork.emplace(curTime + time[id][3], id);

                ++returned;
            }
            else if (!lftWait.empty() && crossed < n) {
                auto [_, id] = lftWait.top();
                lftWait.pop();

                curTime += time[id][0];
                rhtWork.emplace(curTime + time[id][1], id);

                ++crossed;
            }
        }

        return curTime;
    }
};
