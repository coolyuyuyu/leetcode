class Solution {
public:
    vector<int> dfs(const vector<vector<int>>& graph, int node, int parent, const string& labels, vector<int>& ans) {
        vector<int> cnts(26, 0);
        for (int child : graph[node]) {
            if (child == parent) {
                continue;
            }

            vector<int> childCnts = dfs(graph, child, node, labels, ans);
            for (int i = 0; i < 26; ++i) {
                cnts[i] += childCnts[i];
            }
        }
        ans[node] = ++cnts[labels[node] - 'a'];

        return cnts;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> ans(n, 0);
        dfs(graph, 0, -1, labels, ans);

        return ans;
    }
};
