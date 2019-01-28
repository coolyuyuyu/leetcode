class Solution {
public:
    int dfs1(vector<vector<int>>& graph, int root, vector<int>& counts, unordered_set<int>& seen) {
        seen.emplace(root);

        int distance = 0;
        for (int child : graph[root]) {
            if (seen.find(child) == seen.end()) {
                distance += dfs1(graph, child, counts, seen);
                counts[root] += counts[child];
                distance += counts[child];
            }
        }
        counts[root] += 1;

        return distance;
    }

    void dfs2(vector<vector<int>>& graph, int node, vector<int>& counts, int parentDistance, vector<int>& distances, unordered_set<int>& seen) {
        if (seen.emplace(node).second) {
            distances[node] = parentDistance - counts[node] + (graph.size() - counts[node]);
            for (int child : graph[node]) {
                dfs2(graph, child, counts, distances[node], distances, seen);
            }
        }
    }

    vector<int> sumOfDistancesInTreeRecv(int N, vector<vector<int>>& edges) {
        vector<vector<int>> graph(N);
        for (vector<int>& edge : edges) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }

        int root = 0;
        vector<int> counts(N, 0);
        unordered_set<int> seen;
        vector<int> distances(N);
        distances[root] = dfs1(graph, root, counts, seen);

        seen.clear();
        dfs2(graph, root, counts, distances[root] + N, distances, seen);
        return distances;
    }

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        return sumOfDistancesInTreeRecv(N, edges);
    }
};