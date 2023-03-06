class Solution {
public:
    int dfs1(const vector<vector<int>>& adj, int node, int parent, const set<pair<int, int>>& guesses) {
        int numGuessRight = (guesses.find({parent, node}) != guesses.end() ? 1 : 0);
        for (int child : adj[node]) {
            if (child == parent) {
                continue;
            }

            numGuessRight += dfs1(adj, child, node, guesses);
        }

        return numGuessRight;
    }

    int dfs2(const vector<vector<int>>& adj, int node, int parent, const set<pair<int, int>>& guesses, int numGuessRight, int k) {
        int numValidTree = (k <= numGuessRight ? 1 : 0);
        for (int child : adj[node]) {
            if (child == parent) {
                continue;
            }

            int tmp = numGuessRight;
            if (guesses.find({node, child}) != guesses.end()) {
                --tmp;
            }
            if (guesses.find({child, node}) != guesses.end()) {
                ++tmp;
            }
            numValidTree += dfs2(adj, child, node, guesses, tmp, k);
        }

        return numValidTree;
    }

    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        set<pair<int, int>> g;
        for (const auto& guess : guesses) {
            g.emplace(guess[0], guess[1]);
        }

        int node = 0, parent = -1;
        int numGuessRight = dfs1(adj, node, parent, g);
        int numValidTree = dfs2(adj, node, parent, g, numGuessRight, k);
        return numValidTree;
    }
};
