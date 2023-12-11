class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> next[n];
        for (int i = 0; i < n; ++i) {
            if (i == headID) { continue; }
            next[manager[i]].push_back(i);
        }

        int ret = 0;
        for (queue<pair<int, int>> q({{headID, 0}}); !q.empty();) {
            auto [id, t] = q.front();
            q.pop();

            ret = std::max(ret, t);

            for (int nxt : next[id]) {
                q.emplace(nxt, t + informTime[id]);
            }
        }

        return ret;
    }
};
