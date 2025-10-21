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
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, std::greater<>> minPQ; // <cost, x, y>
        for (const auto& conn : connections) {
            int x = conn[0], y = conn[1], cost = conn[2];
            minPQ.emplace(cost, x - 1, y - 1);
        }

        DisjointSets ds(n);

        int ret = 0;
        while (ds.size() > 1 && !minPQ.empty()) {
            auto [cost, x, y] = minPQ.top();
            minPQ.pop();

            if (!ds.connected(x, y)) {
                ret += cost;
                ds.merge(x, y);
            }
        }

        return ds.size() > 1 ? -1 : ret;
    }

    int prim(int n, vector<vector<int>>& connections) {
        vector<pair<int, int>> graph[n]; // <node, cost>
        for (const auto& conn : connections) {
            int x = conn[0] - 1, y = conn[1] - 1, cost = conn[2];
            graph[x].emplace_back(y, cost);
            graph[y].emplace_back(x, cost);
        }

        vector<bool> visited(n, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>> minPQ; // <cost, node>
        minPQ.emplace(0, 0);

        int ret = 0;
        while (!minPQ.empty()) {
            auto [cost, x] = minPQ.top();
            minPQ.pop();

            if (visited[x]) { continue; }
            visited[x] = true;

            ret += cost;

            for (const auto& [y, cost] : graph[x]) {
                if (visited[y]) { continue; }
                minPQ.emplace(cost, y);
            }
        }

        return std::count(visited.begin(), visited.end(), true) == n ? ret: -1;
    }

    int minimumCost(int n, vector<vector<int>>& connections) {
        //return kruskal(n, connections);
        return prim(n, connections);
    }
};
