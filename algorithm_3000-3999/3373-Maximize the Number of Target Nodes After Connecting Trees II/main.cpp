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
        int m = graph1.size(), n = graph2.size();

        std::function<void(const vector<vector<int>>& graph, int cur, int pre, int color, vector<int>& colors)> twoColoring = [&](const vector<vector<int>>& graph, int cur, int pre, int color, vector<int>& colors) {
            colors[cur] = color;
            for (int nxt : graph[cur]) {
                if (nxt == pre) { continue; }
                twoColoring(graph, nxt, cur, 1 - color, colors);
            }
        };
        vector<int> colors1(m), colors2(n);
        twoColoring(graph1, 0, -1, 0, colors1);
        twoColoring(graph2, 0, -1, 0, colors2);
        int cntColor0OfGraph1 = std::count(colors1.begin(), colors1.end(), 0), cntColor1OfGraph1 = m - cntColor0OfGraph1;
        int cntColor0OfGraph2 = std::count(colors2.begin(), colors2.end(), 0), cntColor1OfGraph2 = n - cntColor0OfGraph2;

        vector<int> ret(m);
        for (int i = 0; i < m; ++i) {
            ret[i] = (colors1[i] == 0 ? cntColor0OfGraph1 : cntColor1OfGraph1) + max(cntColor0OfGraph2,cntColor1OfGraph2);
        };

        return ret;
    }
};
