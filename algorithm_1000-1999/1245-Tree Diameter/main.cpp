class Solution {
public:
    int f1(vector<vector<int>>& edges) {
        // Assume the longest path of the graph is in between node a and b.
        // Start from any node s, the farest node against s must be a or b

        int n = edges.size() + 1;
        vector<int> graph[n];
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        std::function<pair<int, int>(int, int)> f = [&](int cur, int pre) {
            pair<int, int> ret = {-1, cur};
            for (int nxt : graph[cur]) {
                if (nxt == pre) { continue; }

                auto [d, v] = f(nxt, cur);
                if (d > ret.first) {
                    ret = {d, v};
                }
            }
            ret.first += 1;

            return ret;
        };

        auto [_, s] = f(0, -1);
        auto [d , t] = f(s, -1);
        return d;
    }

    int f2(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> graph[n];
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int ret = 0;
        std::function<int(int, int)> f = [&](int cur, int pre) {
            int d1 = 0, d2 = 0;
            for (int nxt : graph[cur]) {
                if (nxt == pre) { continue; }

                int d = f(nxt, cur);
                if (d >= d1) {
                    d2 = d1;
                    d1 = d;
                }
                else if (d > d2) {
                    d2 = d;
                }
            }
            ret = std::max(ret, d1 + d2);

            return d1 + 1;
        };
        f(0, -1);

        return ret;
    }

    int treeDiameter(vector<vector<int>>& edges) {
        return f1(edges);
        //return f2(edges);
    }
};
