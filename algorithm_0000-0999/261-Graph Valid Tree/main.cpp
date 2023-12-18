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
    bool bfs(int n, vector<vector<int>>& edges) {
        if (edges.size() + 1 != n) {
            return false;
        }

        int degree[n];
        std::fill(degree, degree + n, 0);
        vector<int> next[n];
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            ++degree[a];
            ++degree[b];
            next[a].push_back(b);
            next[b].push_back(a);
        }

        int cnt = 0;

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degree[i] <= 1) {
                ++cnt;
                q.push(i);
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int nxt : next[cur]) {
                if (--degree[nxt] == 1) {
                    ++cnt;
                    q.push(nxt);
                }
            }
        }

        return cnt == n;
    }

    bool dfs(int n, vector<vector<int>>& edges) {
        if (edges.size() + 1 != n) {
            return false;
        }

        vector<int> next[n];
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            next[a].push_back(b);
            next[b].push_back(a);
        }

        enum class State : unsigned char {
            kNone,
            kProcessing,
            kProcessed,
        };
        State states[n];
        std::fill(states, states + n, State::kNone);
        std::function<bool(int, int)> checkCycle = [&](int cur, int pre) {
            switch (states[cur]) {
                case State::kProcessing: return true;
                case State::kProcessed: return false;
            }

            states[cur] = State::kProcessing;
            for (int nxt : next[cur]) {
                if (nxt == pre) { continue; }
                if (checkCycle(nxt, cur)) {
                    return true;
                }
            }
            states[cur] = State::kProcessed;

            return false;
        };
        for (int i = 0; i < n; ++i) {
            if (checkCycle(i, -1)) {
                return false;
            }
        }
        return true;
    }

    bool dsu(int n, vector<vector<int>>& edges) {
        if (edges.size() + 1 != n) {
            return false;
        }

        DisjointSets ds(n);
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            if (!ds.merge(a, b)) {
                return false;
            }
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        //return bfs(n, edges);
        //return dfs(n, edges);
        return dsu(n, edges);
    }
};
