class Solution {
public:
    void allPathsSourceTargetHelper(vector<vector<int>>& graph, int target, vector<vector<int>>& paths, vector<int>& path) {
        int cur = path.back();
        if (cur == target) {
            paths.push_back(path);
            return;
        }

        vector<int>& neighbors = graph[cur];
        for (size_t i = 0; i < neighbors.size(); ++i) {
            path.push_back(neighbors[i]);
            allPathsSourceTargetHelper(graph, target, paths, path);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        path.push_back(0);
        allPathsSourceTargetHelper(graph, graph.size() - 1, paths, path);

        return paths;
    }
};