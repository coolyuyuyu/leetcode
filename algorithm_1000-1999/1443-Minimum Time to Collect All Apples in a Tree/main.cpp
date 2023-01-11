class Solution {
public:
    int dfs(const vector<vector<int>>& graph, int node, int parent, const vector<bool>& hasApple) {
        int time = 0;
        for (int child : graph[node]) {
            if (child == parent) {
                continue;
            }

            int childTime = dfs(graph, child, node, hasApple);
            if (childTime || hasApple[child]) {
                time += childTime;
                time += 2;
            }
        }

        return time;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return dfs(graph, 0, -1, hasApple);
    }
};
