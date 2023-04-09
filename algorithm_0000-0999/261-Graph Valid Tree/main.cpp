class DisjointSets {
public:
    DisjointSets(int n)
        : m_roots(n) {
        std::iota(m_roots.begin(), m_roots.end(), 0);
    }

    bool merge(int elem1, int elem2) {
        int root1 = root(elem1), root2 = root(elem2);
        if (root1 == root2) {
            return false;
        }
        else {
            m_roots[root1] = root2;
            return true;
        }
    }

private:
    int root(int elem) const {
        if (m_roots[elem] != elem) {
            m_roots[elem] = root(m_roots[elem]);
        }
        return m_roots[elem];
    }
    mutable vector<int> m_roots;
};

class Solution {
public:
    bool bfs(int n, const vector<vector<int>>& edges) {
        if ((edges.size() + 1) != n) {
            return false;
        }

        vector<vector<int>> nexts(n);
        vector<int> degree(n, 0);
        for (const auto& edge : edges) {
            nexts[edge[0]].push_back(edge[1]);
            nexts[edge[1]].push_back(edge[0]);
            ++degree[edge[0]];
            ++degree[edge[1]];
        }

        int cnt = 0;

        queue<int> q;
        for (int v = 0; v < n; ++v) {
            if (degree[v] <= 1) {
                q.push(v);
                ++cnt;
            }
        }

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int next : nexts[v]) {
                if (--degree[next] == 1) {
                    q.push(next);
                    ++cnt;
                }
            }
        }

        return cnt == n;
    }

    bool dfs(int n, const vector<vector<int>>& edges) {
        if ((edges.size() + 1) != n) {
            return false;
        }

        vector<vector<int>> nexts(n);
        for (const auto& edge : edges) {
            nexts[edge[0]].push_back(edge[1]);
            nexts[edge[1]].push_back(edge[0]);
        }

        enum class State {
            kNone,
            kProcessing,
            kProcessed,
        };
        vector<State> states(n, State::kNone);
        std::function<bool(int, int)> checkCycle = [&nexts, &states, &checkCycle](int node, int parent) {
            if (states[node] == State::kProcessing) {
                return true;
            }
            if (states[node] == State::kProcessed) {
                return false;
            }


            states[node] = State::kProcessing;
            for (int next : nexts[node]) {
                if (next == parent) {
                    continue;
                }
                if (checkCycle(next, node)) {
                    return true;
                }
            }

            states[node] = State::kProcessed;
            return false;
        };


        for (int v = 0; v < n; ++v) {
            if (checkCycle(v, -1)) {
                return false;
            }
        }

        return true;
    }

    bool unionfind(int n, const vector<vector<int>>& edges) {
        if ((edges.size() + 1) != n) {
            return false;
        }

        DisjointSets ds(n);
        for (const auto& edge : edges) {
            if (!ds.merge(edge[0], edge[1])) {
                return false;
            }
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        //return bfs(n, edges);
        //return dfs(n, edges);
        return unionfind(n, edges);
    }
};
