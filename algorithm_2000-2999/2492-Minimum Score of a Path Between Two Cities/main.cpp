class DisjointSets {
public:
    DisjointSets(int n)
        : m_roots(n) {
        std::iota(m_roots.begin(), m_roots.end(), 0);
    }

    void merge(int elem1, int elem2) {
        int root1 = root(elem1), root2 = root(elem2);
        if (root1 != root2) {
            m_roots[root1] = root2;
        }
    }

    bool connected(int elem1, int elem2) const {
        return root(elem1) == root(elem2);
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
    int byUnionFind(int n, vector<vector<int>>& roads) {
        DisjointSets ds(n + 1);
        for (const auto& road : roads) {
            ds.merge(road[0], road[1]);
        }

        int ret = INT_MAX;
        for (const auto& road : roads) {
            if (ds.connected(1, road[0])) {
                ret = std::min(ret, road[2]);
            }
        }

        return ret;
    }

    int byBFS(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (const auto& road : roads) {
            graph[road[0]].emplace_back(road[1], road[2]);
            graph[road[1]].emplace_back(road[0], road[2]);
        }

        int ret = INT_MAX;
        vector<bool> visited(n + 1);
        queue<int> q({1});
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (visited[node]) {
                continue;
            }
            visited[node] = true;

            for (const auto& next : graph[node]) {
                ret = std::min(ret, next.second);
                q.push(next.first);
            }
        }

        return ret;
    }

    int minScore(int n, vector<vector<int>>& roads) {
        //return byUnionFind(n, roads);
        return byBFS(n, roads);
    }
};
