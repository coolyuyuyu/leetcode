class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
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

        std::function<void(const vector<vector<int>>&, vector<bool>&)> twoColor = [](const vector<vector<int>>& graph, vector<bool>& colors) {
            bool color = false;
            for (queue<pair<int, int>> q({{0, -1}}); !q.empty(); color = !color) {
                for (int i = q.size(); 0 < i--;) {
                    auto [cur, pre] = q.front();
                    q.pop();

                    colors[cur] = color;

                    for (int nxt : graph[cur]) {
                        if (nxt == pre) { continue; }
                        q.emplace(nxt, cur);
                    }
                }
            }
        };

        vector<bool> colors1(n), colors2(m);
        twoColor(graph1, colors1);
        twoColor(graph2, colors2);
        int cntColor0OfGraph1 = std::count(colors1.begin(), colors1.end(), false), cntColor1OfGraph1 = n - cntColor0OfGraph1;
        int cntColor0OfGraph2 = std::count(colors2.begin(), colors2.end(), false), cntColor1OfGraph2 = m - cntColor0OfGraph2;


        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            ret[i] = (colors1[i] == false ? cntColor0OfGraph1 : cntColor1OfGraph1) + std::max(cntColor0OfGraph2, cntColor1OfGraph2);
        }

        return ret;
    }
};
