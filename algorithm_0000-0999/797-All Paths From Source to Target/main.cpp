class Solution {
public:
    void dfs(const vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& paths) {
        int node = path.back();
        for (int neighbor : graph[node]) {
            path.push_back(neighbor);
            dfs(graph, path, paths);
            path.pop_back();
        }

        if ((path.back() + 1) == graph.size()) {
            paths.push_back(path);
        }
    }

    vector<vector<int>> dfs(const vector<vector<int>>& graph) {
        vector<int> path = {0};
        vector<vector<int>> paths;
        dfs(graph, path, paths);
        return paths;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        return dfs(graph);
    }
};
