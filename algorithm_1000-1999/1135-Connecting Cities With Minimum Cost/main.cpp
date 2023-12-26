class DisjointSets {
public:
    DisjointSets(int n)
        : m_parents(n)
        , m_size(n) {
        std::iota(m_parents.begin(), m_parents.end(), 0);
    }

    DisjointSets(const DisjointSets& ds)
        : m_parents(ds.m_parents)
        , m_size(ds.m_size) {
    }

    void merge(int elem1, int elem2) {
        int root1 = root(elem1), root2 = root(elem2);
        if (root1 != root2) {
            m_parents[root1] = root2;
            --m_size;
        }
    }

    bool connected(int elem1, int elem2) const {
        return root(elem1) == root(elem2);
    }

    int size() const {
        return m_size;
    }

private:
    int root(int elem) const {
        if (m_parents[elem] != elem) {
            m_parents[elem] = root(m_parents[elem]);
        }

        return m_parents[elem];
    }

    mutable vector<int> m_parents;
    int m_size;
};

class Solution {
public:
    int kruskal(int n, vector<vector<int>>& connections) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, std::greater<tuple<int, int, int>>> pq;
        for (const auto& connection : connections) {
            int u = connection[0] - 1, v = connection[1] - 1, cost = connection[2];
            pq.emplace(cost, u, v);
        }

        int ret = 0;
        DisjointSets ds(n);
        while (1 < ds.size() && !pq.empty()) {
            auto [cost, u, v] = pq.top();
            pq.pop();

            if (!ds.connected(u, v)) {
                ds.merge(u, v);
                ret += cost;
            }
        }

        return ds.size() == 1 ? ret : -1;
    }

    int prim(int n, vector<vector<int>>& connections) {
        vector<pair<int, int>> graph[n];
        for (const auto& connection : connections) {
            int u = connection[0] - 1, v = connection[1] - 1, cost = connection[2];
            graph[u].emplace_back(cost, v);
            graph[v].emplace_back(cost, u);
        }

        bool visited[n];
        std::fill(visited, visited + n, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
        pq.emplace(0, 0);

        int ret = 0;
        int cnt = 0;
        while (cnt < n && !pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (visited[u]) { continue; }
            visited[u] = true;

            ++cnt;
            ret += cost;

            for (const auto& [c, v] : graph[u]) {
                if (visited[v]) { continue; }
                pq.emplace(c, v);
            }
        }

        return cnt == n ? ret : -1;
    }

    int minimumCost(int n, vector<vector<int>>& connections) {
        //return kruskal(n, connections);
        return prim(n, connections);
    }
};
