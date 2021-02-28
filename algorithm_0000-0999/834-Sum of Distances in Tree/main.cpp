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

    vector<int> sumOfDistancesInTreeIter(int N, vector<vector<int>>& edges) {
        int root = 0;
        vector<vector<int>> tree(N);
        vector<int> parents(N); {
            vector<unordered_set<int>> graph(N);
            for (vector<int>& edge : edges) {
                graph[edge[0]].emplace(edge[1]);
                graph[edge[1]].emplace(edge[0]);
            }

            queue<int> nodes;
            nodes.emplace(root);
            while (!nodes.empty()) {
                size_t n = nodes.size();
                for (size_t i = 0; i < n; ++i) {
                    int node = nodes.front();
                    nodes.pop();

                    for (int child : graph[node]) {
                        graph[child].erase(node);
                        nodes.emplace(child);

                        parents[child] = node;
                    }
                }
            }
            for (int node = 0; node < N; ++node) {
                tree[node] = vector(graph[node].begin(), graph[node].end());
            }

            parents[root] = -1;
        }

        vector<int> counts(N, 0);
        int distance = 0; {
            queue<int> leaves; {
                for (int node = 0; node < N; ++node) {
                    if (tree[node].empty()) {
                        leaves.emplace(node);
                    }
                }
            }
            vector<int> childCounts(N); {
                for (int node = 0; node < N; ++node) {
                    childCounts[node] = tree[node].size();
                }
            }
            while (!leaves.empty()) {
                int leave = leaves.front();
                leaves.pop();

                int parent = parents[leave];
                if (0 <= parent) {
                    counts[parent] += (counts[leave] + 1);
                    if (--childCounts[parent] == 0) {
                        leaves.emplace(parent);
                    }
                }
                distance += counts[leave];
                counts[leave] += 1;
            }
        }

        vector<int> distances(N); distances[root] = distance; {
            queue<int> nodes;
            nodes.emplace(root);
            while (!nodes.empty()) {
                int node = nodes.front();
                nodes.pop();
                for (int child : tree[node]) {
                    distances[child] = distances[node] - counts[child] + (N - counts[child]);
                    nodes.emplace(child);
                }
            }
        }
        return distances;
    }

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        //return sumOfDistancesInTreeRecv(N, edges);

        return sumOfDistancesInTreeIter(N, edges);
    }
};