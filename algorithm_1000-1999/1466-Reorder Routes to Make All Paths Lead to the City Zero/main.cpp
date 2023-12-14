class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int, bool>> graph[n];
        for (const auto& connection : connections) {
            graph[connection[0]].emplace_back(connection[1], true);
            graph[connection[1]].emplace_back(connection[0], false);
        }

        queue<pair<int, int>> q;
        q.emplace(0, -1);

        int ret = 0;
        while (!q.empty()) {
            auto [cur, pre] = q.front();
            q.pop();

            for (const auto& [nxt, forward] : graph[cur]) {
                if (nxt == pre) { continue; }

                if (forward) {
                    ++ret;
                }

                q.emplace(nxt, cur);
            }
        }

        return ret;
    }
};
