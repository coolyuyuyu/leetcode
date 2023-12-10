class DisjointSets {
public:
    DisjointSets(int n)
        : m_parents(n)
        , m_size(n) {
        std::iota(m_parents.begin(), m_parents.end(), 0);
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
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        auto cmp = [](const auto& e1, const auto& e2){ return std::get<2>(e1) > std::get<2>(e2); };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> edges(cmp);
        for (int i = 0; i < n; ++i) {
            edges.emplace(i + 1, 0, wells[i]);
        }
        for (const auto& pipe : pipes) {
            edges.emplace(pipe[0], pipe[1], pipe[2]);
        }

        int ret = 0;
        DisjointSets ds(n + 1);
        while(ds.size() > 1 && !edges.empty()) {
            auto [u, v, cost] = edges.top();
            edges.pop();

            if (ds.connected(u, v)) { continue; }

            ds.merge(u, v);
            ret += cost;
        }

        return ret;
    }
};
