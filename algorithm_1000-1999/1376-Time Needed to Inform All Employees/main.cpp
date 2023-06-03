class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> graph[n];
        for (int i = 0; i < n; ++i) {
            if (0 <= manager[i]) {
                graph[manager[i]].push_back(i);
            }
        }

        stack<pair<int, int>> stk;
        stk.emplace(headID, 0);
        int ret = 0;
        while (!stk.empty()) {
            auto [employee, time] = stk.top();
            stk.pop();

            ret = std::max(ret, time);

            for (int subordinate : graph[employee]) {
                stk.emplace(subordinate, time + informTime[employee]);
            }
        }

        return ret;
    }
};
