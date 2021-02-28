class Solution {
public:
    void makeSet(vector<int>& parents) {
        for (size_t i = 1; i < parents.size(); ++i) {
            parents[i] = i;
        }
    }

    int find(vector<int>& parents, int i) {
        if (parents[i] != i) {
            parents[i] = find(parents, parents[i]);
        }

        return parents[i];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parents(edges.size() + 1);
        makeSet(parents);

        for (auto edge : edges) {
            int rootA = find(parents, edge[0]);
            int rootB = find(parents, edge[1]);
            if (rootA == rootB) {
                return edge;
            }

            parents[rootA] = rootB;
        }

        assert(false);
        return {};
    }
};