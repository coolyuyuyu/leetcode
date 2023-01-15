class Solution {
public:
    long long dfs(const vector<vector<int>>& graph, int node, int parent, const vector<int>& price, map<pair<int, int>, long long>& cache) {
        auto itr = cache.find({node, parent});
        if (itr != cache.end()) {
            return itr->second;
        }

        long long childSum = 0;
        for (int child : graph[node]) {
            if (child == parent) {
                continue;
            }

            childSum = std::max(childSum, dfs(graph, child, node, price, cache));
        }

        return cache[{node, parent}] = price[node] + childSum;
    }

    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        long long maxCost = 0;
        map<pair<int, int>, long long> cache;
        for (int root = 0; root < n; ++root) {
            long long maxPath = dfs(graph, root, -1, price, cache);
            maxCost = std::max(maxCost, maxPath - price[root]);
        }

        return maxCost;
    }
};
