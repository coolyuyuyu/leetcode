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

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, std::greater<tuple<int, int, int>>> pq;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int cost = std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1]);
                pq.emplace(cost, i, j);
            }
        }

        int ret = 0;
        DisjointSets ds(n);
        while (1 < ds.size() && !pq.empty()) {
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

        vector<pair<int, int>> graph[n];
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int cost = std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1]);
                graph[i].emplace_back(cost, j);
                graph[j].emplace_back(cost, i);
            }
        }

        bool visited[n];
        std::fill(visited, visited + n, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
        pq.emplace(0, 0);

        int ret = 0;
        int cnt = 0;
        while (cnt < n && !pq.empty()) {
            auto [cost, i] = pq.top();
            pq.pop();

            if (visited[i]) { continue; }
            visited[i] = true;

            ++cnt;
            ret += cost;

            for (const auto [c, j] : graph[i]) {
                if (visited[j]) { continue; }
                pq.emplace(c, j);
            }
        }

        return ret;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        //return kruskal(points);
        return prim(points);
    }
};
