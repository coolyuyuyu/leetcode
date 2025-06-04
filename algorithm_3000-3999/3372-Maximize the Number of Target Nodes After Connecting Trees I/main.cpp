class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        std::function<vector<vector<int>>(const vector<vector<int>>&)> buildGraph = [](const vector<vector<int>>& edges) {
            vector<vector<int>> graph(edges.size() + 1);
            for (const auto& edge : edges) {
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
            }

            return graph;
        };
        vector<vector<int>> graph1(buildGraph(edges1)), graph2(buildGraph(edges2));
        int n = graph1.size(), m = graph2.size();

        std::function<int(const vector<vector<int>>&, int, int)> countCovered = [](const vector<vector<int>>& graph, int src, int k) {
            int ret = 0;
            for (queue<pair<int, int>> q({{src, -1}});!q.empty() && k >= 0; k--) {
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

        int maxG2CoveredCnt = 0;
        for (int j = 0; j < m; ++j) {
            maxG2CoveredCnt = std::max(maxG2CoveredCnt, countCovered(graph2, j, k - 1));
        }

        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            ret[i] = countCovered(graph1, i, k) + maxG2CoveredCnt;
        }

        return ret;
    }
};
