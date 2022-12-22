class Solution {
public:
    void dfs1(const vector<vector<int>>& neighbors, int node, int parent, int depth, vector<int>& cnts, int& sumDists) {
        sumDists += depth;

        cnts[node] = 1;
        for (int neighbor : neighbors[node]) {
            if (neighbor == parent) {
                continue;
            }
            dfs1(neighbors, neighbor, node, depth + 1, cnts, sumDists);
            cnts[node] += cnts[neighbor];
        }
    }

    void dfs2(const vector<vector<int>>& neighbors, int node, int parent, const vector<int>& cnts, vector<int>& coverages) {
        if (parent != -1) {
            coverages[node] = coverages[parent] + (neighbors.size() - cnts[node]) - (cnts[node]);
        }

        for (int neighbor : neighbors[node]) {
            if (neighbor == parent) {
                continue;
            }
            dfs2(neighbors, neighbor, node, cnts, coverages);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> neighbors(n);
        for (const auto& edge : edges) {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }
        vector<int> cnts(n);
        vector<int> ret(n, 0);

        int src = 0;
        dfs1(neighbors, src, -1, 0, cnts, ret[src]);
        dfs2(neighbors, src, -1, cnts, ret);
        return ret;
    }
};

// sumDist(child) = sumDist(parent) + (N - cnts(child)) - (cnts(child))
