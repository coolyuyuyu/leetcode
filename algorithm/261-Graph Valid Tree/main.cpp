class Solution {
public:
    void makeSet(vector<int>& parents) {
        for (size_t i = 0; i < parents.size(); ++i) {
            parents[i] = i;
        }
    }

    int find(vector<int>& parents, int i) {
        if (parents[i] != i) {
            parents[i] = find(parents, parents[i]);
        }

        return parents[i];
    }

    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.size() + 1 != n) {
            return false;
        }

        vector<int> parents(n);
        makeSet(parents);
        for (const pair<int, int>& edge : edges) {
            int rootA = find(parents, edge.first);
            int rootB = find(parents, edge.second);
            if (rootA == rootB) {
                return false;
            }

            parents[rootA] = rootB;
        }

        return true;
    }
};