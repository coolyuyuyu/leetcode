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

        int root(int elem) const {
            if (m_parents[elem] != elem) {
                m_parents[elem] = root(m_parents[elem]);
            }

            return m_parents[elem];
        }

        mutable vector<int> m_parents;
    };

    int union_find(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();

        map<int, vector<int>> nodeGroups; // order matters
        for (int node = 0; node < n; ++node) {
            nodeGroups[vals[node]].push_back(node);
        }

        vector<vector<int>> adjLists(n);
        for (const auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            if (vals[node1] <= vals[node2]) { // edge attach to one side only
                adjLists[node2].push_back(node1);
            }
            else {
                adjLists[node1].push_back(node2);
            }
        }

        int ret = 0;
        DisjointSets ds(n);
        for (const auto& [_, nodes] : nodeGroups) {
            for (int node : nodes) {
                for (int neighbor : adjLists[node]) {
                    ds.merge(node, neighbor);
                }
            }

            unordered_map<int, int> componentSizes;
            for (int node : nodes) {
                ++componentSizes[ds.root(node)];
            }
            for (const auto& [_, size] : componentSizes) {
                ret += (size * (size - 1) / 2);
            }
        }

        return ret + vals.size();
    }

    map<int, int> dfs(const vector<vector<int>>& adjLists, int node, int parent, const vector<int>& vals, int& numPaths) {
        map<int, int> nodeFreqs;
        ++nodeFreqs[vals[node]];

        for (int child : adjLists[node]) {
            if (child == parent) {
                continue;
            }

            map<int, int> childFreqs = dfs(adjLists, child, node, vals, numPaths);
            childFreqs.erase(childFreqs.begin(), childFreqs.lower_bound(vals[node]));
            if (nodeFreqs.size() < childFreqs.size()) {
                std::swap(nodeFreqs, childFreqs);
            }

            for (const auto& [val, freq] : childFreqs) {
                if (nodeFreqs.find(val) != nodeFreqs.end()) {
                    numPaths += (nodeFreqs[val] * freq);
                }
            }

            for (const auto& [val, freq] : childFreqs) {
                nodeFreqs[val] += freq;
            }
        }

        return nodeFreqs;
    }

    int dfs(const vector<int>& vals, const vector<vector<int>>& edges) {
        vector<vector<int>> adjLists(vals.size());
        for (const auto& edge : edges) {
            adjLists[edge[0]].push_back(edge[1]);
            adjLists[edge[1]].push_back(edge[0]);
        }

        int numPaths = 0;
        dfs(adjLists, 0, -1, vals, numPaths);
        return numPaths + vals.size();
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        //return union_find(vals, edges);
        return dfs(vals, edges);
    }
};
