class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) {
            return {0};
        }

        vector<unordered_set<int>> adj(n);
        for (const pair<int, int>& edge : edges) {
            adj[edge.first].emplace(edge.second);
            adj[edge.second].emplace(edge.first);
        }

        vector<int> leaves;
        for (int node = 0; node < n; ++node) {
            if (adj[node].size() == 1) {
                leaves.emplace_back(node);
            }
        }

        while (2 < n) {
            n -= leaves.size();
            vector<int> leavesTmp;
            for (int leave : leaves) {
                int parent = *(adj[leave].begin());

                adj[parent].erase(leave);
                if (adj[parent].size() == 1) {
                    leavesTmp.emplace_back(parent);
                }
            }
            leaves.swap(leavesTmp);
        }

        return leaves;
    }
};