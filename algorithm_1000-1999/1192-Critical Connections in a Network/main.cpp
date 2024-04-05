class Solution {
public:
    // TLE
    vector<vector<int>> bruteforce(int n, vector<vector<int>>& connections) {
        unordered_set<int> graph[n];
        for (const auto& conn : connections) {
            int a = conn[0], b = conn[1];
            graph[a].insert(b);
            graph[b].insert(a);
        }

        bool visited[n];
        std::function<void(int, int)> dfs = [&](int cur, int pre) {
            visited[cur] = true;

            for (int nxt : graph[cur]) {
                if (nxt == pre) { continue; }
                if (visited[nxt]) { continue; }
                dfs(nxt, cur);
            }
        };
        std::function<int()> computeComponents = [&]() {
            int numComponents = 0;

            std::fill(visited, visited + n, false);
            for (int i = 0; i < n; ++i) {
                if (!visited[i]) {
                    ++numComponents;
                    dfs(i, -1);
                }
            }

            return numComponents;
        };

        int numComponents = computeComponents();

        vector<vector<int>> ret;
        for (const auto& conn : connections) {
            int a = conn[0], b = conn[1];
            graph[a].erase(b);
            graph[b].erase(a);

            if (computeComponents() != numComponents) {
                ret.push_back({a, b});
            }

            graph[a].insert(b);
            graph[b].insert(a);
        }

        return ret;
    }

    vector<vector<int>> tarjan(int n, vector<vector<int>>& connections) {
        vector<int> graph[n];
        for (const auto& conn : connections) {
            int a = conn[0], b = conn[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<vector<int>> ret;

        int t;
        int dfn[n];
        int low[n];
        int parent[n];
        bool visited[n];
        std::function<void(int)> dfs = [&](int u) {
            assert(visited[u] == false);
            visited[u] = true;

            dfn[u] = low[u] = t++;
            for (int v : graph[u]) {
                if (v == parent[u]) { continue; }

                if (visited[v]) {
                    low[u] = std::min(low[u], dfn[v]);
                }
                else {
                    parent[v] = u;
                    dfs(v);

                    if (low[v] > dfn[u]) {
                        ret.push_back({u, v});
                    }

                    low[u] = std::min(low[u], low[v]);
                }
            }
        };

        t = 0;
        std::fill(parent, parent + n, -1);
        std::fill(visited, visited + n, false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }


        return ret;
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //return bruteforce(n, connections);
        return tarjan(n, connections);
    }
};
