class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, bool>>> graph(n); // <next, foreward>
        for (const auto& conn : connections) {
            graph[conn[0]].emplace_back(conn[1], true);
            graph[conn[1]].emplace_back(conn[0], false);
        }

        int ret = 0;
        queue<tuple<int, int, bool>> q({{0, -1, false}});
        while (!q.empty()) {
            auto [node, parent, forward] = q.front();
            q.pop();

            if (forward) {
                ++ret;
            }

            for (const auto[next, forward] : graph[node]) {
                if (next == parent) {
                    continue;
                }
                q.emplace(next, node, forward);
            }
        }

        return ret;
    }
};
