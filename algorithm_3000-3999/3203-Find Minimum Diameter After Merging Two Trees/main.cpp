class Solution {
public:
    // 1245. Tree Diameter
    int treeDiameter(vector<vector<int>>& edges) {
        // Assume the longest path of the tree is in between node a and b.
        // Start from any node s, the farest node against s must be a or b.

        int n = edges.size() + 1;
        vector<int> graph[n];
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        std::function<pair<int, int>(int)> bfs = [&](int src) {
            queue<pair<int, int>> q({{src, -1}});
            int leaf, depth;
            for (depth = -1; !q.empty(); ++depth) {
                leaf = q.front().first;
                for (int i = q.size(); 0 < i--;) {
                    auto [cur, pre] = q.front();
                    q.pop();

                    for (int nxt : graph[cur]) {
                        if (nxt == pre) { continue; }
                        q.emplace(nxt, cur);
                    }
                }
            }

            return pair<int, int>{leaf, depth};
        };

        auto [s, maxDistfromS] = bfs(0);
        auto [t, maxDistfromT] = bfs(s);

        return maxDistfromT;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1 = treeDiameter(edges1);
        int d2 = treeDiameter(edges2);
        return std::max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1});
    }
};
