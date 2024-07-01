class Solution {
public:
    vector<vector<int>> bfs(int n, vector<vector<int>>& edges) {
        vector<int> graph[n];
        int ins[n]; std::fill(ins, ins + n, 0);
        for (const auto& edge : edges) {
            int from = edge[0], to = edge[1];
            graph[from].push_back(to);
            ++ins[to];
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (ins[i] == 0) {
                q.push(i);
            }
        }

        vector<unordered_set<int>> tmp(n);
        while (!q.empty()) {
            int from = q.front();
            q.pop();
            for (int to : graph[from]) {
                tmp[to].insert(from);
                tmp[to].insert(tmp[from].begin(), tmp[from].end());
                if (--ins[to] == 0) {
                    q.push(to);
                }
            }
        }

        vector<vector<int>> ret(n);
        for (int i = 0; i < n; ++i) {
            ret[i].assign(tmp[i].begin(), tmp[i].end());
            std::sort(ret[i].begin(), ret[i].end());
        }

        return ret;
    }

    vector<vector<int>> dfs1(int n, vector<vector<int>>& edges) {
        vector<int> graph[n];
        for (const auto& edge : edges) {
            int from = edge[0], to = edge[1];
            graph[to].push_back(from);
        }

        bool visited[n];
        std::function<void(int)> f = [&](int u) {
            visited[u] = true;
            for (int v : graph[u]) {
                if (visited[v]) { continue; }
                f(v);
            }
        };

        vector<vector<int>> ret(n);
        for (int i = 0; i < n; ++i) {
            std::fill(visited, visited + n, false);
            f(i);
            for (int j = 0; j < n; ++j) {
                if (j == i) { continue; }
                if (!visited[j]) { continue; }
                ret[i].push_back(j);
            }
        }

        return ret;
    }

    vector<vector<int>> dfs2(int n, vector<vector<int>>& edges) {
        vector<int> graph[n];
        for (const auto& edge : edges) {
            int from = edge[0], to = edge[1];
            graph[from].push_back(to);
        }

        vector<vector<int>> ret(n);
        std::function<void(int, int)> f = [&](int ancestor, int current) {
            for (int child : graph[current]) {
                if (!ret[child].empty() && ret[child].back() == ancestor) { continue; }
                ret[child].push_back(ancestor);
                f(ancestor, child);
            }
        };
        for (int i = 0; i < n; ++i) {
            f(i, i);
        }

        return ret;
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        //return bfs(n, edges);
        //return dfs1(n, edges);
        return dfs2(n, edges);
    }
};
