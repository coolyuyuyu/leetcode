class Solution {
public:
    class DisjointSets {
    public:
        DisjointSets(int size)
            : m_parents(size) {
            std::iota(m_parents.begin(), m_parents.end(), 0);
        }

        void merge(int elem1, int elem2) {
            int root1 = root(elem1), root2 = root(elem2);
            if (root1 != root2) {
                m_parents[root1] = root2;
            }
        }

        bool connected(int elem1, int elem2) const {
            return root(elem1) == root(elem2);
        }

        int root(int elem) const {
            if (m_parents[elem] != elem) {
                m_parents[elem] = root(m_parents[elem]);
            }

            return m_parents[elem];
        }

        mutable vector<int> m_parents;
    };

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        auto cost = [&](const vector<int>& edge) -> int {
            return std::max(vals[edge[0]], vals[edge[1]]);
        };
        auto comp = [&](const vector<int>& edge1, const vector<int>& edge2) {
            return cost(edge1) < cost(edge2);
        };
        std::sort(edges.begin(), edges.end(), comp);

        int n = vals.size();

        int ret = n;
        DisjointSets ds(n);
        unordered_set<int> nodes;
        for (int preCost = -1, i = 0; i <= edges.size(); ++i) {
            int curCost = (i == edges.size() ? INT_MAX : cost(edges[i]));
            if (preCost < curCost) {
                unordered_map<int, int> sizes;
                for (int node : nodes) {
                    ++sizes[ds.root(node)];
                }
                for (const auto& [_, size] : sizes) {
                    ret += (size * (size - 1) / 2);
                }

                nodes.clear();
            }

            if (i < edges.size()) {
                int curCost = cost(edges[i]);
                if (vals[edges[i][0]] == curCost) {
                    nodes.insert(edges[i][0]);
                }
                if (vals[edges[i][1]] == curCost) {
                    nodes.insert(edges[i][1]);
                }
                ds.merge(edges[i][0], edges[i][1]);

                preCost = curCost;
            }
        }

        return ret;
    }
};
