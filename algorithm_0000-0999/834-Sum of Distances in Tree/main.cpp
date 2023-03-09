class Solution {
public:
    int dfs1(const vector<vector<int>>& adj, int node, int parent, int depth, vector<int>& counts) {
        int sum = depth;
        for (int child : adj[node]) {
            if (child == parent) {
                continue;
            }

            sum += dfs1(adj, child, node, depth + 1, counts);
            counts[node] += counts[child];
        }

        return sum;
    }

    void dfs2(const vector<vector<int>>& adj, int node, int parent, const vector<int>& counts, vector<int>& sums) {
        for (int child : adj[node]) {
            if (child == parent) {
                continue;
            }

            sums[child] = sums[node] - counts[child] + (adj.size() - counts[child]);
            dfs2(adj, child, node, counts, sums);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int node = 0, parent = -1;
        vector<int> counts(n, 1); // counts[i]: the number of nodes for tree rooted at i
        vector<int> sums(n, 0); // sums[i]: sum of the distances between the ith node and all other nodes
        sums[node] = dfs1(adj, node, parent, 0, counts);
        dfs2(adj, node, parent, counts, sums);

        return sums;
    }
};
