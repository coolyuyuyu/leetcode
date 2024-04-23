class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> graph[n];
        vector<int> degrees(n, 0);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);

            ++degrees[u];
            ++degrees[v];
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degrees[i] <= 1) {
                q.push(i);
            }
        }

        while (n > 2) {
            n -= q.size();
            for (int i = q.size(); 0 < i--;) {
                int u = q.front();
                q.pop();

                for (int v : graph[u]) {
                    if (--degrees[v] == 1) {
                        q.push(v);
                    }
                }
            }
        }

        vector<int> ret;
        while (!q.empty()) {
            ret.push_back(q.front());
            q.pop();
        }

        return ret;
    }
};
