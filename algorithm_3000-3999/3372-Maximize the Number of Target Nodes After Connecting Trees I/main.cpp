class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> graph1(n, vector<int>()), graph2(m, vector<int>());
        for (const auto& edge : edges1) {
            graph1[edge[0]].push_back(edge[1]);
            graph1[edge[1]].push_back(edge[0]);
        }
        for (const auto& edge : edges2) {
            graph2[edge[0]].push_back(edge[1]);
            graph2[edge[1]].push_back(edge[0]);
        }

        std::function<int(const vector<vector<int>>&, int, int)> countCovered = [](const vector<vector<int>>& graph, int src, int k) {
            int ret = 0;
            for (queue<pair<int, int>> q({{src, -1}}); k >= 0; --k) {
                ret += q.size();

                for (int i = q.size(); 0 < i--;) {
                    auto [cur, pre] = q.front();
                    q.pop();

                    for (int nxt : graph[cur]) {
                        if (nxt == pre) { continue; }
                        q.emplace(nxt, cur);
                    }
                }
            }

            return ret;
        };

        int maxG2Covered = 0;
        for (int i = 0; i < m; ++i) {
            maxG2Covered = std::max(maxG2Covered, countCovered(graph2, i, k - 1));
        }

        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            ret[i] = countCovered(graph1, i, k) + maxG2Covered;
        }

        return ret;
    }
};
