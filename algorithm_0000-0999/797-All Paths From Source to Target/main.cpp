class Solution {
public:
    vector<vector<int>> dfs(vector<vector<int>>& graph) {
        vector<vector<int>> ret;
        std::function<void(vector<int>&)>dfs = [&](vector<int>& path) {
            if (path.back() == graph.size() - 1) {
                ret.push_back(path);
                return;
            }

            for (int nxt : graph[path.back()]) {
                path.push_back(nxt);
                dfs(path);
                path.pop_back();
            }
        };

        vector<int> path = {0};
        dfs(path);

        return ret;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        return dfs(graph);
    }
};
