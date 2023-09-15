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
    int kruskal(vector<vector<int>>& points) {
        int n = points.size();

        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq; // {cost, i, j}
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                pq.push({cost, i, j});
            }
        }

        DisjointSets ds(n);
        int ret = 0;
        while (1 < ds.size()) {
            auto [cost, i, j] = pq.top();
            pq.pop();

            if (!ds.connected(i, j)) {
                ds.merge(i, j);
                ret += cost;
            }
        }

        return ret;
    }

    int prim(vector<vector<int>>& points) {
        int n = points.size();

        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                graph[i].emplace_back(cost, j);
                graph[j].emplace_back(cost, i);
            }
        }

        vector<int> visited(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {cost, j}

        int src = 0;
        visited[src] = true;
        for (const auto& elem : graph[src]) {
            pq.push(elem);
        }

        int ret = 0;
        for (int cnt = 1; cnt < n;) {
            auto [cost, to] = pq.top();
            pq.pop();

            if (!visited[to]) {
                visited[to] = true;
                for (const auto& elem : graph[to]) {
                    pq.push(elem);
                }

                ret += cost;
                ++cnt;
            }
        }

        return ret;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        //return kruskal(points);
        return prim(points);
    }
};
