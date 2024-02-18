class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = tasks.size();

        queue<int> pendingTasks;
        priority_queue<array<int, 3>, vector<array<int, 3>>, std::greater<array<int, 3>>> busyPQ; // <servTime, servW, servIdx>
        priority_queue<array<int, 2>, vector<array<int, 2>>, std::greater<array<int, 2>>> freePQ; // <servW, servIdx>
        for (int i = 0; i < servers.size(); ++i) {
            freePQ.push({servers[i], i});
        }

        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            pendingTasks.push(i);
            while (!busyPQ.empty() && busyPQ.top()[0] <= i) {
                auto [_, servW, servIdx] = busyPQ.top();
                busyPQ.pop();
                freePQ.push({servW, servIdx});
            }
            while (!pendingTasks.empty() && !freePQ.empty()) {
                auto [servW, servIdx] = freePQ.top();
                freePQ.pop();
                int taskIdx = pendingTasks.front();
                pendingTasks.pop();
                busyPQ.push({i + tasks[taskIdx], servW, servIdx});
                ret[taskIdx] = servIdx;
            }
        }

        while (!pendingTasks.empty()) {
            int taskIdx = pendingTasks.front();
            pendingTasks.pop();
            auto [servTime, servW, servIdx] = busyPQ.top();
            busyPQ.pop();
            busyPQ.push({servTime + tasks[taskIdx], servW, servIdx});
            ret[taskIdx] = servIdx;
        }

        return ret;
    }
};
